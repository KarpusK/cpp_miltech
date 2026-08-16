#define _USE_MATH_DEFINES
#include <cmath>
#include <fstream>
#include <iostream>
#include <cstring>
#include <filesystem>
#include <sstream>
#include "json.hpp"
using json = nlohmann::json;

// На початку файлу:
#define ENABLE_LOG	1
#define ENABLE_DEBUG  1

#if ENABLE_LOG
#define LOG(msg) std::cout << "[LOG] " << msg << std::endl
#else
#define LOG(msg)
#endif

#if ENABLE_DEBUG
#define DEBUG(msg) std::cout << "[DEBUG] " << msg << std::endl
#else
#define DEBUG(msg)
#endif

// ==========================================================
// Стани дрона (enum)
// ==========================================================
enum DroneState
{
    STOPPED = 0,
    ACCELERATING = 1,
    DECELERATING = 2,
    TURNING = 3,
    MOVING = 4
};

// ==========================================================
// Константи
// ==========================================================
const int   TARGET_COUNT = 5;
const int   TARGET_ARRAY_SIZE = 120;
const float g_gravity = 9.81f;
const int   MAX_STEPS = 10000;
const int   NUM_TIME_APPROXIMATION_STEPS = 10;

#define STOP_WHEN_TURNING

// ==========================================================
// Структури
// ==========================================================
struct Coord {
    float x;
    float y;
	float z;

    // Додавання координат
    Coord operator+(const Coord& other) const {
        return { x + other.x, y + other.y, z + other.z };
    }

    // Віднімання координат
    Coord operator-(const Coord& other) const {
        return { x - other.x, y - other.y, z - other.z };
    }

    // Множення на скаляр
    Coord operator*(float s) const {
        return { x * s, y * s, z * s };
    }

	// Ділення на скаляр
	Coord operator/(float s) const {
		return { x / s, y / s, z / s };
	}

	// Порівняння координат
	bool operator==(const Coord& other) const {
		return std::fabs(x - other.x) < 1e-6f && std::fabs(y - other.y) < 1e-6f && std::fabs(z - other.z) < 1e-6f;
	}

	// Довжина вектора
	float length() const {
		return std::sqrt(x * x + y * y);
	}

	// Нормалізація вектора
	Coord normalized() const {
		float len = length();
		if (len > 1e-6f) {
			return (*this) / len;
		}
		return { 0.0f, 0.0f, 0.0f }; // Уникнення ділення на нуль
	}
};

struct AmmoParams {
    char name[32];
    float mass; 	// маса (кг)
    float drag; 	// коефіцієнт опору
    float lift; 	// коефіцієнт підйому
};

struct DroneConfig {
    Coord startPos;     	// початкова позиція (x, y)
    float altitude;     	// висота
    float initialDir;   	// початковий напрямок (рад)
    float attackSpeed;  	// швидкість атаки (м/с)
    float accelPath;    	// шлях розгону (м)
    char  ammoName[32]; 	// обрані боєприпаси
    float arrayTimeStep;	// крок часу масиву цілей
    float simTimeStep;  	// крок симуляції
    float hitRadius;    	// радіус влучення
    float angularSpeed; 	// кутова швидкість (рад/с)
    float turnThreshold;	// поріг повороту (рад)
};

struct SimStep {
    Coord pos;          	// позиція дрона
    float direction;    	// напрямок (рад)
    int   state;        	// стан автомата (0-4)
    int   targetIdx;    	// індекс поточної цілі
    Coord dropPoint;    	// точка скиду (куди летить дроn)
    Coord aimPoint;     	// куди впаде бомба (якщо скинути зараз)
    Coord predictedTarget;  // прогнозована позиція цілі
};

// Вихідні масиви
SimStep simSteps[MAX_STEPS];

// Масиви координат цілей
float targetXInTime[TARGET_COUNT][TARGET_ARRAY_SIZE];
float targetYInTime[TARGET_COUNT][TARGET_ARRAY_SIZE];

// ------------------------------------------------------------
// Утиліти читання/валідaції JSON
// ------------------------------------------------------------
bool loadJsonFile(const std::string& path, json& out, std::string& err) {
    std::ifstream f(path);
    if (!f.is_open()) {
        std::ostringstream ss; ss << "Cannot open file: " << path;
        err = ss.str();
        return false;
    }
    try {
        f >> out;
    } catch (const std::exception& e) {
        std::ostringstream ss; ss << "Parse error in " << path << ": " << e.what();
        err = ss.str();
        return false;
    }
    return true;
}

// ------------------------------------------------------------
// Інтерполяція позиції цілі
// ------------------------------------------------------------
void interpolateTarget(int targetIdx, float t, float arrayTimeStep,
    float& outTx, float& outTy)
{
    int idx = (int)std::floor(t / arrayTimeStep) % TARGET_ARRAY_SIZE;
    int next = (idx + 1) % TARGET_ARRAY_SIZE;
    float frac = (t / arrayTimeStep) - std::floor(t / arrayTimeStep);

    outTx = targetXInTime[targetIdx][idx]
        + (targetXInTime[targetIdx][next] - targetXInTime[targetIdx][idx]) * frac;
    outTy = targetYInTime[targetIdx][idx]
        + (targetYInTime[targetIdx][next] - targetYInTime[targetIdx][idx]) * frac;
}

//-------------------------------------------------------------
// Екстраполяція цілі у часі
//-------------------------------------------------------------
// Лінійна екстраполяція: знаємо лише поточний відрізок (idx, idx+1),
// прогнозуємо що ціль продовжує рухатись з тією ж швидкістю і напрямком.
// currentTime - поточний час, dt - на скільки секунд вперед прогнозуємо.
void extrapolateTarget(int targetIdx, float currentTime, float dt,
    float arrayTimeStep, float& outTx, float& outTy)
{
    int idx = (int)std::floor(currentTime / arrayTimeStep) % TARGET_ARRAY_SIZE;
    int next = (idx + 1) % TARGET_ARRAY_SIZE;

    // Швидкість цілі на поточному відрізку
    float vx = (targetXInTime[targetIdx][next] - targetXInTime[targetIdx][idx]) / arrayTimeStep;
    float vy = (targetYInTime[targetIdx][next] - targetYInTime[targetIdx][idx]) / arrayTimeStep;

    // Поточна позиція (інтерполяція)
    float curX, curY;
    interpolateTarget(targetIdx, currentTime, arrayTimeStep, curX, curY);

    // Екстраполяція
    outTx = curX + vx * dt;
    outTy = curY + vy * dt;
}

// ------------------------------------------------------------
// Нормалізація кута до [-PI, PI]
// ------------------------------------------------------------
float normalizeAngle(float a)
{
    while (a > M_PI) a -= 2.0f * (float)M_PI;
    while (a < -M_PI) a += 2.0f * (float)M_PI;
    return a;
}

// ------------------------------------------------------------
// Балістика з ДЗ 1: час польоту (метод Кардано)
// ------------------------------------------------------------
float calcTimeOfFall(float z0, float v0, float m, float d, float l)
{
    float a = d * g_gravity * m - 2 * d * l * v0;
    float b = -3 * g_gravity * m + 3 * d * l * v0;
    float c = 6 * m * z0;

    if (std::fabs(a) < 1e-12f)
        return std::sqrt(2.0f * z0 / g_gravity);

    float p = -b * b / (3 * a * a);
    float q = (2 * b * b * b) / (27 * a * a * a) + c / a;

    if (p >= 0)
        return std::sqrt(2.0f * z0 / g_gravity);

    float arg = 3 * q / (2 * p) * std::sqrt(-3 / p);
    if (std::fabs(arg) > 1)
        return std::sqrt(2.0f * z0 / g_gravity);

    float phi = std::acos(arg);
    float t = 2 * std::sqrt(-p / 3) * std::cos((phi + 4 * (float)M_PI) / 3) - b / (3 * a);
    return t > 0 ? t : std::sqrt(2.0f * z0 / g_gravity);
}

// ------------------------------------------------------------
// Балістика: горизонтальна дистанція
// ------------------------------------------------------------
float calcHDistance(float t, float V0, float m, float d, float l)
{
    float l2 = l * l;
    float l4 = l2 * l2;

    float h = t * V0
        - (d * std::pow(t, 2) * V0) / (2 * m)
        + (std::pow(t, 3) * (6 * d * g_gravity * l * m - 8 * std::pow(d, 2) * (-1 + l2) * V0)) / (36 * std::pow(m, 2))
        + (std::pow(t, 4) * (-6 * std::pow(d, 2) * g_gravity * l * (1 + l2 + l4) * m
            + 3 * std::pow(d, 3) * l2 * (1 + l2) * V0
            + 6 * std::pow(d, 3) * l4 * (1 + l2) * V0))
        / (36 * std::pow(1 + l2, 2) * std::pow(m, 3))
        + (std::pow(t, 5) * (3 * std::pow(d, 3) * g_gravity * std::pow(l, 3) * m
            - 3 * std::pow(d, 4) * l2 * (1 + l2) * V0))
        / (36 * (1 + l2) * std::pow(m, 4));

    return h;
}

void getIntermediateAndDropPoint(float currentX, float currentY, float targetX, float targetY, float hDistance, float accelerationPath, float& outIntermediateX, float& outIntermediateY,
    float& outFireX, float& outFireY, bool& outHasIntermediate)
{
    float distanceToTarget = std::sqrt(pow(targetX - currentX, 2) + pow(targetY - currentY, 2));

    outHasIntermediate = hDistance + accelerationPath > distanceToTarget;

    if (outHasIntermediate)
    {
        if (fabs(distanceToTarget) < 1e-6)
        {
            outIntermediateX = targetX - (hDistance + accelerationPath);
            outIntermediateY = targetY;
            distanceToTarget = hDistance + accelerationPath;
        }
        else
        {
            outIntermediateX = targetX - (targetX - currentX) * (hDistance + accelerationPath) / distanceToTarget;
            outIntermediateY = targetY - (targetY - currentY) * (hDistance + accelerationPath) / distanceToTarget;
            distanceToTarget = std::sqrt(pow(targetX - outIntermediateX, 2) + pow(targetY - outIntermediateY, 2));
        }
    }

    float ratio = (distanceToTarget - hDistance) / std::max(1e-9f, distanceToTarget);

    outFireX = currentX + (targetX - currentX) * ratio;
    outFireY = currentY + (targetY - currentY) * ratio;
}

bool needStop(float desiredDir, float currentDir, float angleThreshold)
{
#ifdef STOP_WHEN_TURNING
    float deltaAngle = normalizeAngle(desiredDir - currentDir);

    return std::fabs(deltaAngle) > angleThreshold;
#else
    return false;
#endif
}

float accel(float speed, float accelPath)
{
    return speed * speed / (2.0f * accelPath);
}

float accelTime(float speed, float acc)
{
    return speed / acc;
}

float accelTimeFromDist(float dist, float acc)
{
    return std::sqrt(2.0f * dist / acc);
}

float accelPathFromSpeed(float speed, float acc)
{
    return (speed * speed) / (2.0f * acc);
}

float distFromSpeedAndAccel(float speed, float acc)
{
    return (speed * speed) / (2.0f * acc);
}

// ------------------------------------------------------------
// Розрахунок часу польоту до заданої координати
// ------------------------------------------------------------
float calcTimeOfFlight(float currentX, float currentY, float targetX, float targetY, float currentDir, float angleThreshold, float angularSpeed, float currentSpeed, float maxSpeed, float accelPath, bool needToStopAtTarget)
{
    float totalTimeToPoint = 0.0f;
    float desiredDir = std::atan2(targetY - currentY, targetX - currentX);
    float a = accel(maxSpeed, accelPath);

    bool ns = needStop(desiredDir, currentDir, angleThreshold);

    if (ns)
    {
        float pathToStop = (currentSpeed * currentSpeed) / (2.0f * a);

        currentX += std::cos(currentDir) * pathToStop;
        currentY += std::sin(currentDir) * pathToStop;

        totalTimeToPoint += accelTime(currentSpeed, a);
        totalTimeToPoint += std::fabs(normalizeAngle(desiredDir - currentDir)) / angularSpeed;

        currentSpeed = 0;
        currentDir = desiredDir;
    }

    float distanceToTarget = std::hypot(targetX - currentX, targetY - currentY);
    float decceleratePath = std::min(needToStopAtTarget ? accelPathFromSpeed(maxSpeed, a) : 0, distanceToTarget);
    distanceToTarget -= decceleratePath;
    totalTimeToPoint += accelTimeFromDist(decceleratePath, a);

    float accelDist = std::min(accelPathFromSpeed(maxSpeed, a) - accelPathFromSpeed(currentSpeed, a), distanceToTarget);
    totalTimeToPoint += accelTimeFromDist(accelDist, a);
    distanceToTarget -= accelDist;
    totalTimeToPoint += distanceToTarget / maxSpeed;

    return totalTimeToPoint;
}

Coord calcAimPoint(float currentX, float currentY, float direction, float hDist)
{
    return {
        currentX + std::cos(direction) * hDist,
        currentY + std::sin(direction) * hDist,
    };
}

// ------------------------------------------------------------
// MAIN
// ------------------------------------------------------------
int main()
{
    // --- Читання config.json ---
    json jc;
    std::string err;
    if (!loadJsonFile("config.json", jc, err)) {std::cerr << err << std::endl; return 1;}

    DroneConfig cfg;
    cfg.startPos.x = jc["Drone"]["startPos"]["x"];
    cfg.startPos.y = jc["Drone"]["startPos"]["y"];
	cfg.startPos.z = jc["Drone"]["startPos"]["z"];
    cfg.altitude = jc["Drone"]["altitude"];
    cfg.initialDir = jc["Drone"]["initialDirection"];
    cfg.attackSpeed = jc["Drone"]["attackSpeed"];
    cfg.accelPath = jc["Drone"]["accelerationPath"];
    std::strncpy(cfg.ammoName, jc["Drone"]["ammoName"].get<std::string>().c_str(), sizeof(cfg.ammoName) - 1);
    cfg.ammoName[sizeof(cfg.ammoName) - 1] = '\0';
    cfg.arrayTimeStep = jc["Drone"]["targetArrayTimeStep"];
    cfg.simTimeStep = jc["Drone"]["simulation"]["timeStep"];
    cfg.hitRadius = jc["Drone"]["simulation"]["hitRadius"];
    cfg.angularSpeed = jc["Drone"]["angularSpeed"];
    cfg.turnThreshold = jc["Drone"]["turnThreshold"];

    LOG("Config loaded: speed=" << cfg.attackSpeed << " start=(" << cfg.startPos.x << "," << cfg.startPos.y << "," << cfg.startPos.z << ")");

    // --- Пошук боєприпасу з ammo.json ---
    json ja;
    if (!loadJsonFile("ammo.json", ja, err)) {std::cerr << err << std::endl; return 1;}

    int ammoCount = (int)ja.size();
    if (ammoCount <= 0) { std::cerr << "ammo.json: no entries" << std::endl; return 1; }

    AmmoParams* ammo = new AmmoParams[ammoCount];
    int bombIdx = -1;
    for (int i = 0; i < ammoCount; i++) {
        std::strncpy(ammo[i].name, ja[i]["name"].get<std::string>().c_str(), 31);
        ammo[i].mass = ja[i]["mass"];
        ammo[i].drag = ja[i]["drag"];
        ammo[i].lift = ja[i]["lift"];

        // If config specifies a name - try to match
        if (std::string(cfg.ammoName) == std::string(ammo[i].name)) { bombIdx = i; break;}
    }
    if (bombIdx == -1) { bombIdx = 0; LOG("ammo.json: requested ammo not found, falling back to first entry");}
    LOG("Ammo used: " << ammo[bombIdx].name << " mass=" << ammo[bombIdx].mass);

    float m = ammo[bombIdx].mass;
    float d = ammo[bombIdx].drag;
    float l = ammo[bombIdx].lift;
    delete[] ammo;

    // --- Читання targets.json ---
    json jt;
    if (!loadJsonFile("targets.json", jt, err)) {std::cerr << err << std::endl; return 1;}

    int tgtCount = jt["targetCount"];
    int timeSteps = jt["timeSteps"];
    if (tgtCount != TARGET_COUNT || timeSteps != TARGET_ARRAY_SIZE) {
        std::cerr << "Wrong targets.json size (unexpected after validation)" << std::endl;
        return 1;
    }
    for (int i = 0; i < TARGET_COUNT; i++) {
        for (int j = 0; j < TARGET_ARRAY_SIZE; j++) {
            targetXInTime[i][j] = jt["targets"][i]["positions"][j]["x"];
            targetYInTime[i][j] = jt["targets"][i]["positions"][j]["y"];
        }
    }

    // --- Параметри руху дрона ---
    float acceleration = cfg.attackSpeed * cfg.attackSpeed / (2.0f * cfg.accelPath);

    float droneX = cfg.startPos.x;
    float droneY = cfg.startPos.y;
    float droneZ = cfg.startPos.z;
    float direction = cfg.initialDir;
    float speed = 0.0f;
    DroneState state = STOPPED;

    float currentTime = 0.0f;
    int currentTarget = -1;
    float targetDir = cfg.initialDir;

#ifdef STOP_WHEN_TURNING
    float turnRemaining = 0.0f;
#endif

    int step = 0;

    // Попередній розрахунок балістичних констант (залежать лише від висоти та снаряду)
    float flightTime = calcTimeOfFall(cfg.startPos.z, cfg.attackSpeed, m, d, l);
    float hDist = calcHDistance(flightTime, cfg.attackSpeed, m, d, l);

    // --- Основний цикл симуляції ---
    while (step < MAX_STEPS)
    {
        float bestTime = 1e9f;
        int bestTarget = 0;
        float bestPredX = droneX, bestPredY = droneY;
        float bestFireX = droneX, bestFireY = droneY;
        float desiredDirectionForBest = direction;
        float fx = 0, fy = 0;

        for (int targetId = 0; targetId < TARGET_COUNT; ++targetId)
        {
            float predX = 0, predY = 0;
            float totalTime = 0;
            bool hasIntermediate = false;

            // We'll use currentTime == 0 for initial decision
            for (int iter = 0; iter < NUM_TIME_APPROXIMATION_STEPS; iter++)
            {
                extrapolateTarget(targetId, currentTime, totalTime + flightTime, cfg.arrayTimeStep, predX, predY);

                float intermediateX = 0, intermediateY = 0;
                float fireX = 0, fireY = 0;
                getIntermediateAndDropPoint(droneX, droneY, predX, predY, hDist, cfg.accelPath, intermediateX, intermediateY, fireX, fireY, hasIntermediate);
                
                // Якщо дрон вже летить до поточної цілі - не відступаємо назад
                if (hasIntermediate && targetId == currentTarget && (state == MOVING || state == ACCELERATING))
                    hasIntermediate = false;

                totalTime = 0;
                if (hasIntermediate)
                {
                    
                    totalTime = calcTimeOfFlight(droneX, droneY, intermediateX, intermediateY, direction, cfg.turnThreshold, cfg.angularSpeed, speed, cfg.attackSpeed, cfg.accelPath, true);
                    float directionToFire = std::atan2(fireY - intermediateY, fireX - intermediateX);
                    totalTime += std::fabs(normalizeAngle(directionToFire - direction)) / cfg.angularSpeed;
                    totalTime += calcTimeOfFlight(droneX, droneY, fireX, fireY, directionToFire, cfg.turnThreshold, cfg.angularSpeed, cfg.attackSpeed, cfg.attackSpeed, cfg.accelPath, false);

                    fx = fireX;
                    fy = fireY;
                }
                else
                {
                    totalTime = calcTimeOfFlight(droneX, droneY, fireX, fireY, direction, cfg.turnThreshold, cfg.angularSpeed, speed, cfg.attackSpeed, cfg.accelPath, false);
                    fx = fireX;
                    fy = fireY;
                }
            } // iter

            if (totalTime < bestTime)
            {
                bestTime = totalTime;
                bestTarget = targetId;
                bestPredX = predX;
                bestPredY = predY;
                bestFireX = fx;
                bestFireY = fy;
            }
        }

		currentTarget = bestTarget;

        // Бажаний напрямок на fire point найкращої цілі
        desiredDirectionForBest = std::atan2(bestFireY - droneY, bestFireX - droneX);

        // 4. Записати дані кроку у вихідні масиви
        simSteps[step].pos.x = droneX;
        simSteps[step].pos.y = droneY;
        simSteps[step].direction = direction;
        simSteps[step].state = (int)state;
        simSteps[step].targetIdx = currentTarget;
		simSteps[step].dropPoint = { bestFireX, bestFireY };
        simSteps[step].aimPoint = { calcAimPoint(droneX, droneY, direction, hDist) };
        simSteps[step].predictedTarget = { bestPredX, bestPredY };

        float deltaPath = 0;
        float deltaAngle = normalizeAngle(desiredDirectionForBest - direction);

        // 6. Автомат станів (самоуправлінний, як у ДЗ3)
        switch (state)
        {
        case STOPPED:
        {
            if (std::fabs(deltaAngle) > cfg.turnThreshold)
            {
                state = TURNING;
            }
            else
            {
                direction = desiredDirectionForBest;
                state = ACCELERATING;
            }
            break;
        }

        case ACCELERATING:
        {
            if (std::fabs(deltaAngle) > cfg.turnThreshold && speed > 0.01f)
            {
                // Треба повернути - спочатку гальмуємо
                state = DECELERATING;
                float prevSpeed = speed;
                speed -= acceleration * cfg.simTimeStep;
                if (speed <= 0) { speed = 0; state = STOPPED; }
                deltaPath = (prevSpeed + speed) / 2.0f * cfg.simTimeStep;
            }
            else
            {
                // Малі поправки курсу на льоту
                if (std::fabs(deltaAngle) <= cfg.turnThreshold)
                    direction = desiredDirectionForBest;

                float prevSpeed = speed;
                speed += acceleration * cfg.simTimeStep;
                if (speed >= cfg.attackSpeed)
                {
                    speed = cfg.attackSpeed;
                    state = MOVING;
                }
                deltaPath = (prevSpeed + speed) / 2.0f * cfg.simTimeStep;
            }
            break;
        }

        case DECELERATING:
        {
            float prevSpeed = speed;
            speed -= acceleration * cfg.simTimeStep;
            if (speed <= 0)
            {
                speed = 0;
                state = STOPPED;
            }
            deltaPath = (prevSpeed + speed) / 2.0f * cfg.simTimeStep;
            break;
        }

        case TURNING:
        {
            float da = normalizeAngle(desiredDirectionForBest - direction);
            if (std::fabs(da) <= cfg.angularSpeed * cfg.simTimeStep)
            {
                direction = desiredDirectionForBest;
                state = ACCELERATING;
            }
            else
            {
                direction += (da > 0 ? 1.0f : -1.0f) * cfg.angularSpeed * cfg.simTimeStep;
                direction = normalizeAngle(direction);
            }
            break;
        }

        case MOVING:
        {
            if (std::fabs(deltaAngle) > cfg.turnThreshold)
            {
                state = DECELERATING;
                float prevSpeed = speed;
                speed -= acceleration * cfg.simTimeStep;
                if (speed <= 0) { speed = 0; state = STOPPED; }
                deltaPath = (prevSpeed + speed) / 2.0f * cfg.simTimeStep;
            }
            else
            {
                // Малі поправки курсу на льоту
                if (std::fabs(deltaAngle) <= cfg.turnThreshold)
                    direction = desiredDirectionForBest;
                deltaPath = speed * cfg.simTimeStep;
            }
            break;
        }
        }

        droneX += std::cos(direction) * deltaPath;
        droneY += std::sin(direction) * deltaPath;

        // Перевірка влучання: дрон долетів до fire point
        if (state == MOVING &&
            std::hypot(droneX - bestFireX, droneY - bestFireY) <= cfg.hitRadius * 0.25f)
        {
            LOG("Reached fire point - dropping munition.");
			break; // скид боєприпасу, симуляція завершується
        }

        currentTime += cfg.simTimeStep;
        step++;
    }

    // При завершенні:
    LOG("Simulation complete. Steps: " << step);

    // --- Запис simulation.json ---
    int N = step; // кількість кроків (індекс 0..N-1)
    json out;
    out["totalSteps"] = N;
    out["steps"] = json::array();
    for (int i = 0; i < N; i++) {
        json stepj;
        stepj["position"] = { {"x", simSteps[i].pos.x}, {"y", simSteps[i].pos.y} };
        stepj["direction"] = simSteps[i].direction;
        stepj["state"] = simSteps[i].state;
        stepj["targetIndex"] = simSteps[i].targetIdx;
        stepj["dropPoint"] = { {"x", simSteps[i].dropPoint.x},
                                   {"y", simSteps[i].dropPoint.y} };
        stepj["aimPoint"] = { {"x", simSteps[i].aimPoint.x},
                                   {"y", simSteps[i].aimPoint.y} };
        stepj["predictedTarget"] = { {"x", simSteps[i].predictedTarget.x},
                                   {"y", simSteps[i].predictedTarget.y} };
        out["steps"].push_back(stepj);
    }

    std::ofstream fout("simulation.json");
    if (!fout.is_open()) { std::cerr << "Cannot write simulation.json" << std::endl; return 1; }
    fout << out.dump(2);  // 2 = відступ для читабельності
    fout.close();

    return 0;
}