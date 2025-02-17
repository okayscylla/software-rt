#pragma once
#include "math/vec3.h"
#include <array>

class Mat4 {
    public:
    Mat4 operator*(const Mat4& term) const; // multiply matrix by matrix
    Mat4& operator*=(const Mat4& term); // update matrix to matrix multiplied matrix
    bool operator==(const Mat4& term) const; // check equality
    bool operator!=(const Mat4& term) const; // check inequality

    Mat4& clear(); // reset to zeros
    Mat4& setDefault(); // reset to identity matrix
    Mat4& transpose(); // transpose matrix
    Mat4 transposed() const; // return new transposed version of current matrix
    
    Mat4& translate(double tx, double ty, double tz); // change translation

    Mat4& rotateX(double theta); // apply x rotation
    Mat4& rotateY(double theta); // apply y rotation
    Mat4& rotateZ(double theta); // apply z rotation

    Mat4& scale(double sx, double sy, double sz); // change scale

    Mat4& lookAt(const Vec3& eye, const Vec3& target, const Vec3& up); // look at target
    Mat4& perspective(double fov, double aspect, double near_value, double far_value); // change perspective

    Mat4 inverse() const; // return a new inversed version of matrix
    double determinant() const; // return determinant of matrix

    std::array<double, 4> column(int index) const;
    std::array<double, 4> row(int index) const;

    double get(int row, int col) const; // get element of matrix
    void set(int row, int col, double value); // set element of matrix

    Mat4() : data(Mat4::identity()) {}; // default constructor
    Mat4(std::array<double, 16> values) : data(values) {}; // create matrix using custom array

    Vec3 transformPoint(const Vec3& point) const; // returns a transformed point
    Vec3 transformDirection(const Vec3&) const; // returns a transformed direction
    Vec3 transformNormal(const Vec3&) const; // returns a transformed normal

    private:
    std::array<double, 16> data; // internal array, column major
    static std::array<double, 16> zeros(); // matrix of only zeros
    static std::array<double, 16> identity(); // identity matrix
};