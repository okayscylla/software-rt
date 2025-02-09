#include "math/vec3.h"
#include "math/constants.h"
#include <cmath>

Vec3 Vec3::operator+(const Vec3& term) const {
    return Vec3(x + term.x, y + term.y, z + term.z);
}

Vec3 Vec3::operator-(const Vec3& term) const {
    return Vec3(x - term.x, y - term.y, z - term.z);
}

Vec3 Vec3::operator*(const Vec3& term) const {
    return Vec3(x * term.x, y * term.y, z * term.z);
}

Vec3 Vec3::operator/(const Vec3& term) const {
    double value_x = 0.0;
    double value_y = 0.0;
    double value_z = 0.0;

    if (term.x > EPSILON) {
        value_x = (x / term.x);
    }

    if (term.y > EPSILON) {
        value_y = (y / term.y);
    }

    if (term.z > EPSILON) {
        value_z = (z / term.z);
    }

    return Vec3(value_x, value_y, value_z);
}

Vec3 Vec3::operator+(double scalar) const{
    return Vec3(x + scalar, y + scalar, z + scalar);
}

Vec3 Vec3::operator-(double scalar) const{
    return Vec3(x - scalar, y - scalar, z - scalar);
}

Vec3 Vec3::operator*(double scalar) const{
    return Vec3(x * scalar, y * scalar, z * scalar);
}

Vec3 Vec3::operator/(double scalar) const{
    double value_x = 0.0;
    double value_y = 0.0;
    double value_z = 0.0;

    if (scalar > EPSILON) {
        value_x = (x / scalar);
        value_y = (y / scalar);
        value_z = (z / scalar);
    }

    return Vec3(value_x, value_y, value_z);
}

double Vec3::dot(const Vec3& term) const {
    return (x * term.x) + (y * term.y) + (z * term.z);
}

double Vec3::length() const {
    return std::sqrt(x*x + y*y + z*z);
}

double Vec3::lengthSquared() const {
    return (x*x + y*y + z*z);
}

Vec3 Vec3::cross(const Vec3& term) const {
    return Vec3(
        y * term.z - z * term.y,
        z * term.x - x * term.z,
        x * term.y - y * term.x
    );
}

Vec3 Vec3::normalise() const {
    double squared_length = Vec3::lengthSquared();

    if (squared_length > EPSILON*EPSILON) {
        double magnitude = Vec3::length();

        return Vec3(
            x / magnitude,
            y / magnitude,
            z / magnitude
        );
    } else {
        return Vec3(
            0,
            0,
            0
        );
    }
}

Vec3 Vec3::reflect(const Vec3& normal) const {
    // TODO: implement reflecting vector across normal vector
    return Vec3()
}