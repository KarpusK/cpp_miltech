#include "mission/MissionProcessor.h"

#include "json.hpp"

#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>

using json = nlohmann::json;

MissionProcessor::MissionProcessor(IConfigLoader* loader, ITargetProvider* provider, IBallisticSolver* solver)
    : loader_(loader), provider_(provider), solver_(solver)
{
}

bool MissionProcessor::init()
{
    if (!loader_ || !provider_ || !solver_)
    {
        std::cerr << "MissionProcessor: component pointer is null" << std::endl;
        return false;
    }

    if (!loader_->load()) return false;
    if (!provider_->load()) return false;

    cfg_ = loader_->getConfig();
    ammo_ = loader_->getAmmoParams();

    BallisticInput input;
    input.config = cfg_;
    input.ammo = ammo_;
    ballistic_ = solver_->solve(input);

    reset();

    LOG("Config loaded: speed=" << cfg_.attackSpeed << " start=(" << cfg_.startPos.x << "," << cfg_.startPos.y << ")");
    LOG("Ammo used: " << ammo_.name << " mass=" << ammo_.mass);
    LOG("Ballistics: flightTime=" << ballistic_.flightTime << " hDistance=" << ballistic_.hDistance);

    return true;
}

bool MissionProcessor::hasNext() const
{
    return !finished_ && stepIndex_ < MAX_STEPS;
}

void MissionProcessor::reset()
{
    acceleration_ = cfg_.attackSpeed * cfg_.attackSpeed / (2.0f * cfg_.accelPath);
    currentPos_ = cfg_.startPos;
    direction_ = cfg_.initialDir;
    speed_ = 0.0f;
    currentTime_ = 0.0f;
    currentTarget_ = -1;
    stepIndex_ = 0;
    state_ = STOPPED;
    finished_ = false;
}

void MissionProcessor::changeSolver(IBallisticSolver* solver)
{
    solver_ = solver;

    if (solver_)
    {
        BallisticInput input;
        input.config = cfg_;
        input.ammo = ammo_;
        ballistic_ = solver_->solve(input);
    }
}

Coord MissionProcessor::interpolateTarget(int targetIdx, float t) const
{
    int idx = static_cast<int>(std::floor(t / cfg_.arrayTimeStep)) % TARGET_ARRAY_SIZE;
    int next = (idx + 1) % TARGET_ARRAY_SIZE;
    float frac = (t / cfg_.arrayTimeStep) - std::floor(t / cfg_.arrayTimeStep);

    Coord a = provider_->getTargetPosition(targetIdx, idx);
    Coord b = provider_->getTargetPosition(targetIdx, next);

    return {a.x + (b.x - a.x) * frac,
            a.y + (b.y - a.y) * frac};
}

Coord MissionProcessor::extrapolateTarget(int targetIdx, float currentTime, float dt) const
{
    int idx = static_cast<int>(std::floor(currentTime / cfg_.arrayTimeStep)) % TARGET_ARRAY_SIZE;
    int next = (idx + 1) % TARGET_ARRAY_SIZE;

    Coord a = provider_->getTargetPosition(targetIdx, idx);
    Coord b = provider_->getTargetPosition(targetIdx, next);

    float vx = (b.x - a.x) / cfg_.arrayTimeStep;
    float vy = (b.y - a.y) / cfg_.arrayTimeStep;

    Coord cur = interpolateTarget(targetIdx, currentTime);
    return {cur.x + vx * dt, cur.y + vy * dt};
}

void MissionProcessor::step()
{
    if (!hasNext()) return;

    float bestTime = 1e9f;
    int bestTarget = 0;
    Coord bestPredPos = currentPos_;
    Coord bestFirePos = currentPos_;

    for (int targetId = 0; targetId < provider_->getTargetCount(); ++targetId)
    {
        Coord predPos = {0.0f, 0.0f};
        Coord firePos = {0.0f, 0.0f};
        Coord intermediatePos = {0.0f, 0.0f};
        Coord selectedFirePos = {0.0f, 0.0f};
        float totalTime = 0.0f;
        bool hasIntermediate = false;

        for (int iter = 0; iter < NUM_TIME_APPROXIMATION_STEPS; ++iter)
        {
            predPos = extrapolateTarget(targetId, currentTime_, totalTime + ballistic_.flightTime);

            intermediatePos = {0.0f, 0.0f};
            firePos = {0.0f, 0.0f};
            getIntermediateAndDropPoint(currentPos_, predPos, ballistic_.hDistance, cfg_.accelPath,
                                        intermediatePos, firePos, hasIntermediate);

            if (hasIntermediate && targetId == currentTarget_ && (state_ == MOVING || state_ == ACCELERATING))
            {
                hasIntermediate = false;
            }

            totalTime = 0.0f;
            if (hasIntermediate)
            {
                Coord currentCopy = currentPos_;
                totalTime = calcTimeOfFlight(currentCopy, intermediatePos, direction_, cfg_.turnThreshold,
                                             cfg_.angularSpeed, speed_, cfg_.attackSpeed, cfg_.accelPath, true);

                float directionToFire = std::atan2(firePos.y - intermediatePos.y, firePos.x - intermediatePos.x);
                totalTime += std::fabs(normalizeAngle(directionToFire - direction_)) / cfg_.angularSpeed;

                Coord intermediateCopy = intermediatePos;
                totalTime += calcTimeOfFlight(intermediateCopy, firePos, directionToFire, cfg_.turnThreshold,
                                              cfg_.angularSpeed, cfg_.attackSpeed, cfg_.attackSpeed,
                                              cfg_.accelPath, false);

                selectedFirePos = firePos;
            }
            else
            {
                Coord currentCopy = currentPos_;
                totalTime = calcTimeOfFlight(currentCopy, firePos, direction_, cfg_.turnThreshold,
                                             cfg_.angularSpeed, speed_, cfg_.attackSpeed, cfg_.accelPath, false);

                selectedFirePos = firePos;
            }
        }

        if (totalTime < bestTime)
        {
            bestTime = totalTime;
            bestTarget = targetId;
            bestPredPos = predPos;
            bestFirePos = selectedFirePos;
        }
    }

    currentTarget_ = bestTarget;

    float desiredDirectionForBest = std::atan2(bestFirePos.y - currentPos_.y, bestFirePos.x - currentPos_.x);

    simSteps_[stepIndex_].pos = currentPos_;
    simSteps_[stepIndex_].direction = direction_;
    simSteps_[stepIndex_].state = static_cast<int>(state_);
    simSteps_[stepIndex_].targetIdx = currentTarget_;
    simSteps_[stepIndex_].dropPoint = bestFirePos;
    simSteps_[stepIndex_].aimPoint = calcAimPoint(currentPos_, direction_, ballistic_.hDistance);
    simSteps_[stepIndex_].predictedTarget = bestPredPos;

    float deltaPath = 0.0f;
    float deltaAngle = normalizeAngle(desiredDirectionForBest - direction_);

    switch (state_)
    {
    case STOPPED:
        if (std::fabs(deltaAngle) > cfg_.turnThreshold)
        {
            state_ = TURNING;
        }
        else
        {
            direction_ = desiredDirectionForBest;
            state_ = ACCELERATING;
        }
        break;

    case ACCELERATING:
        if (std::fabs(deltaAngle) > cfg_.turnThreshold && speed_ > 0.01f)
        {
            state_ = DECELERATING;
            float prevSpeed = speed_;
            speed_ -= acceleration_ * cfg_.simTimeStep;
            if (speed_ <= 0.0f)
            {
                speed_ = 0.0f;
                state_ = STOPPED;
            }
            deltaPath = (prevSpeed + speed_) / 2.0f * cfg_.simTimeStep;
        }
        else
        {
            if (std::fabs(deltaAngle) <= cfg_.turnThreshold)
            {
                direction_ = desiredDirectionForBest;
            }

            float prevSpeed = speed_;
            speed_ += acceleration_ * cfg_.simTimeStep;
            if (speed_ >= cfg_.attackSpeed)
            {
                speed_ = cfg_.attackSpeed;
                state_ = MOVING;
            }
            deltaPath = (prevSpeed + speed_) / 2.0f * cfg_.simTimeStep;
        }
        break;

    case DECELERATING:
    {
        float prevSpeed = speed_;
        speed_ -= acceleration_ * cfg_.simTimeStep;
        if (speed_ <= 0.0f)
        {
            speed_ = 0.0f;
            state_ = STOPPED;
        }
        deltaPath = (prevSpeed + speed_) / 2.0f * cfg_.simTimeStep;
        break;
    }

    case TURNING:
    {
        float da = normalizeAngle(desiredDirectionForBest - direction_);
        if (std::fabs(da) <= cfg_.angularSpeed * cfg_.simTimeStep)
        {
            direction_ = desiredDirectionForBest;
            state_ = ACCELERATING;
        }
        else
        {
            direction_ += (da > 0.0f ? 1.0f : -1.0f) * cfg_.angularSpeed * cfg_.simTimeStep;
            direction_ = normalizeAngle(direction_);
        }
        break;
    }

    case MOVING:
        if (std::fabs(deltaAngle) > cfg_.turnThreshold)
        {
            state_ = DECELERATING;
            float prevSpeed = speed_;
            speed_ -= acceleration_ * cfg_.simTimeStep;
            if (speed_ <= 0.0f)
            {
                speed_ = 0.0f;
                state_ = STOPPED;
            }
            deltaPath = (prevSpeed + speed_) / 2.0f * cfg_.simTimeStep;
        }
        else
        {
            if (std::fabs(deltaAngle) <= cfg_.turnThreshold)
            {
                direction_ = desiredDirectionForBest;
            }
            deltaPath = speed_ * cfg_.simTimeStep;
        }
        break;
    }

    currentPos_.x += std::cos(direction_) * deltaPath;
    currentPos_.y += std::sin(direction_) * deltaPath;

    Coord aimPointAfterMove = calcAimPoint(currentPos_, direction_, ballistic_.hDistance);

    if (state_ == MOVING &&
        std::hypot(currentPos_.x - bestFirePos.x, currentPos_.y - bestFirePos.y) <= cfg_.hitRadius * 0.25f)
    {
        simSteps_[stepIndex_].pos = currentPos_;
        simSteps_[stepIndex_].direction = direction_;
        simSteps_[stepIndex_].state = static_cast<int>(state_);
        simSteps_[stepIndex_].targetIdx = currentTarget_;
        simSteps_[stepIndex_].dropPoint = bestFirePos;
        simSteps_[stepIndex_].aimPoint = aimPointAfterMove;
        simSteps_[stepIndex_].predictedTarget = bestPredPos;

        LOG("Reached fire point - dropping munition.");
        finished_ = true;
        return;
    }

    currentTime_ += cfg_.simTimeStep;
    ++stepIndex_;

    if (stepIndex_ >= MAX_STEPS)
    {
        finished_ = true;
    }
}

bool MissionProcessor::writeResult(const std::string& outputPath) const
{
    LOG("Simulation complete. Steps: " << stepIndex_);

    std::cout << "Current path: " << std::filesystem::current_path() << std::endl;
    std::cout << "Output file: " << std::filesystem::absolute(outputPath) << std::endl;

    json out;
    out["totalSteps"] = stepIndex_;
    out["steps"] = json::array();

    for (int i = 0; i <= stepIndex_ && i < MAX_STEPS; ++i)
    {
        json stepj;
        stepj["position"] = {{"x", simSteps_[i].pos.x}, {"y", simSteps_[i].pos.y}};
        stepj["direction"] = simSteps_[i].direction;
        stepj["state"] = simSteps_[i].state;
        stepj["targetIndex"] = simSteps_[i].targetIdx;
        stepj["dropPoint"] = {{"x", simSteps_[i].dropPoint.x}, {"y", simSteps_[i].dropPoint.y}};
        stepj["aimPoint"] = {{"x", simSteps_[i].aimPoint.x}, {"y", simSteps_[i].aimPoint.y}};
        stepj["predictedTarget"] = {{"x", simSteps_[i].predictedTarget.x}, {"y", simSteps_[i].predictedTarget.y}};
        out["steps"].push_back(stepj);
    }

    std::ofstream fout(outputPath);
    if (!fout.is_open())
    {
        std::cerr << "Cannot write " << outputPath << std::endl;
        return false;
    }

    fout << out.dump(2);
    return true;
}
