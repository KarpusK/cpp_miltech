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
    float length() const { return std::sqrt(x * x + y * y); }
};

struct Target
{
    Coord pos;
    Coord velocity;
};
