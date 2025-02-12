#pragma once
#include "math/vec3.h"
#include <array>

class Mat4 {
    public:
    Mat4 operator*(const Mat4& term) const;
    Mat4 operator*(const Vec3& term) const;

    private:
    std::array<double, 16> data;
}