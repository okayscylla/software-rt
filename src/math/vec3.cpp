#include "math/vec3.h"
#include <cmath>

Vec3::Vec3(float a, float b, float c) : x(a), y(b), z(c);

float Vec3::dot(const Vec3& term) const : {
    return (x * term.x) + (y * term.y) + (z * term.z);
}

float Vec3::length() const : {
    return std::sqrt(x^2 + y^2 + z^2);
}

Vec3 Vec3::cross(const Vec3& term) const : {
    return Vec3(
        y * term.z - z * term.y;
        x * term.z - z * term.x;
        x * term.y - y * term.x;
    )
}

Vec3 Vec3::normalise() const : {
    magnitude = length()

    return Vec3(
        x / magnitude;
        y / magnitude;
        z / magnitude;
    )
}

Vec3 Vec3::reflect() // TODO implement this