#pragma once

#include <cmath>
#include <string>

struct Vector3
{
    Vector3(int x, int y, int z)
        : x(x), y(y), z(z) { }

    Vector3(int x)
        : x(x), y(x), z(x) { }

    double length() const
    {
        return std::sqrt(x * x + y * y + z * z);
    }

    int x, y, z;
};

