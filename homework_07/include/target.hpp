#pragma once

#include <cmath>

struct Coord
{
    float x = 0.0f;
    float y = 0.0f;

    Coord operator+(const Coord& other) const { return {x + other.x, y + other.y}; }
    Coord operator-(const Coord& other) const { return {x - other.x, y - other.y}; }
    Coord operator*(float s) const { return {x * s, y * s}; }
    Coord operator/(float s) const { return {x / s, y / s}; }

    bool operator==(const Coord& other) const
    {
        return std::fabs(x - other.x) < 1e-6f && std::fabs(y - other.y) < 1e-6f;
    }

    float length() const { return std::sqrt(x * x + y * y); }

    Coord normalized() const
    {
        float len = length();
        if (len > 1e-6f) return (*this) / len;
        return {0.0f, 0.0f};
    }
};

struct Target
{
    Coord positions[120];
};
