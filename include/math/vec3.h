#pragma once

class Vec3 {
    public:
    static float x;
    static float y;
    static float z;

    Vec3 operator+(const Vec3& term) const;
    Vec3 operator-(const Vec3& term) const;
    Vec3 operator*(const Vec3& term) const;
    Vec3 operator/(const Vec3& term) const;
    Vec3 operator%(const Vec3& term) const;
    bool operator<=>(const Vec3& term) const;

    float dot(const Vec3& term) const;
    float length() const;

    Vec3 cross(const Vec3& term) const;
    Vec3 normalise() const;
    Vec3 reflect() const; // TODO properly define

    Vec3(float a, float b, float c);
};