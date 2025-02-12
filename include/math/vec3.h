#pragma once

class Vec3 {
    public:
    double x;
    double y;
    double z;

    Vec3 operator+(const Vec3& term) const;
    Vec3 operator-(const Vec3& term) const;
    Vec3 operator*(const Vec3& term) const;
    Vec3 operator/(const Vec3& term) const;

    Vec3 operator+(double scalar) const;
    Vec3 operator-(double scalar) const;
    Vec3 operator*(double scalar) const;
    Vec3 operator/(double scalar) const;

    Vec3 operator+=(const Vec3& term);
    Vec3 operator-=(const Vec3& term);
    Vec3 operator*=(const Vec3& term);
    Vec3 operator/=(const Vec3& term);

    Vec3 operator+=(double scalar);
    Vec3 operator-=(double scalar);
    Vec3 operator*=(double scalar);
    Vec3 operator/=(double scalar);

    bool operator==(const Vec3& term) const;
    bool operator!=(const Vec3& term) const;

    auto operator<=>(const Vec3& term) const;

    Vec3 scale(double factor);

    double dot(const Vec3& term) const;
    double length() const;
    double lengthSquared() const;

    Vec3 cross(const Vec3& term) const;
    Vec3 normalise();
    Vec3 normalised() const;
    Vec3 reflect(const Vec3& normal) const;

    Vec3() : x(0.0), y(0.0), z(0.0) {};
    Vec3(double a, double b, double c) : x(a), y(b), z(c) {};
};