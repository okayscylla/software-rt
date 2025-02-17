#include "math/matrix.h"
#include "math/vec3.h"
#include <array>
#include <cmath>

Mat4 Mat4::operator*(const Mat4& term) const {
    Mat4 product(Mat4::zeros());

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            double k = (get(row, 0) * term.get(0, col) +
                        get(row, 1) * term.get(1, col) +
                        get(row, 2) * term.get(2, col) +
                        get(row, 3) * term.get(3, col));
            product.set(row, col, k);
        }
    }

    return product;
}

Mat4& Mat4::operator*=(const Mat4& term) {
    Mat4 multipliedMatrix(data);

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            double k = (get(row, 0) * term.get(0, col) +
                        get(row, 1) * term.get(1, col) +
                        get(row, 2) * term.get(2, col) +
                        get(row, 3) * term.get(3, col));

            multipliedMatrix.set(row, col, k);
        }
    }
    
    data = multipliedMatrix.data;

    return *this;
}

bool Mat4::operator==(const Mat4& term) const {
    for (int index = 0; index < 16; index++) {
        if (data[index] != term.data[index]) {
            return false;
        }
    }

    return true;
}

bool Mat4::operator!=(const Mat4& term) const {
    return !operator==(term);
}

Mat4& Mat4::clear() {
    data = zeros();

    return *this;
}

Mat4& Mat4::setDefault() {
    data = identity();

    return *this;
}

Mat4& Mat4::transpose() {

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < (row + 1); col++) {
            double swapValue = get(row, col);
            set(row, col, get(col, row));
            set(col, row, swapValue);
        }
    }

    return *this;
}

Mat4 Mat4::transposed() const {
    Mat4 transposed_matrix = Mat4();

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            transposed_matrix.set(row, col, get(col, row));
        }
    }

    return transposed_matrix;
}

Mat4& Mat4::translate(double tx, double ty, double tz) {
    Mat4 translationMatrix;

    translationMatrix.set(0, 3, tx);
    translationMatrix.set(1, 3, ty);
    translationMatrix.set(2, 3, tz);



    return operator*=( translationMatrix);
}

Mat4& Mat4::rotateX(double theta) {
    Mat4 rotationMatrix;

    rotationMatrix.set(1, 1, cos(theta));
    rotationMatrix.set(1, 2, -sin(theta));
    rotationMatrix.set(2, 1, sin(theta));
    rotationMatrix.set(2, 2, cos(theta));

    return operator*=(rotationMatrix);
}

Mat4& Mat4::rotateY(double theta) {
    Mat4 rotationMatrix;

    rotationMatrix.set(0, 0, cos(theta));
    rotationMatrix.set(0, 2, sin(theta));
    rotationMatrix.set(2, 0, -sin(theta));
    rotationMatrix.set(2, 2, cos(theta));

    return operator*=(rotationMatrix);
}

Mat4& Mat4::rotateZ(double theta) {
    Mat4 rotationMatrix;

    rotationMatrix.set(0, 0, cos(theta));
    rotationMatrix.set(0, 1, -sin(theta));
    rotationMatrix.set(1, 0, sin(theta));
    rotationMatrix.set(1, 1, cos(theta));

    return operator*=(rotationMatrix);
}

Mat4& Mat4::scale(double sx, double sy, double sz) {
    Mat4 scaleMatrix;

    scaleMatrix.set(0, 0, sx);
    scaleMatrix.set(1, 1, sy);
    scaleMatrix.set(2, 2, sz);

    return operator*=(scaleMatrix);
}

Mat4& Mat4::lookAt(const Vec3& eye, const Vec3& target, const Vec3& up) {
    Vec3 forward = (eye - target).normalise();
    Vec3 right = up.cross(forward).normalise();
    Vec3 cameraUp = forward.cross(right).normalise();

    set(0, 0, right.x);
    set(0, 1, right.y);
    set(0, 2, right.z);
    
    set(1, 0, cameraUp.x);
    set(1, 1, cameraUp.y);
    set(1, 2, cameraUp.z);
    
    set(2, 0, forward.x);
    set(2, 1, forward.y);
    set(2, 2, forward.z);

    set(0, 3, -right.dot(eye));
    set(1, 3, -cameraUp.dot(eye));
    set(2, 3, -forward.dot(eye));

    return *this;
}

Mat4& Mat4::perspective(double fov, double aspect, double nearValue, double farValue) {
    double tangential_fov = tan(fov / 2);
    double numerator = farValue + nearValue;
    double denominator = nearValue - farValue;

    set(0, 0, 1 / (aspect * tangential_fov));
    set(1, 1, 1 / tangential_fov);
    set(2, 2, numerator / denominator);
    set(2, 3, (2 * farValue * nearValue) / denominator);
    set(3, 2, -1);
    set(3, 3, 0);

    return *this;
}

Mat4 Mat4::inverse() const {

}

double Mat4::determinant() const {

}

std::array<double, 4> Mat4::column(int index) const {
    return std::array<double, 4>({get(0, index), get(1, index), 
        get(2, index), get(3, index)});
}

std::array<double, 4> Mat4::row(int index) const {
    return std::array<double, 4>({get(index, 0), get(index, 1), 
        get(index, 2), get(index, 3)});
}

double Mat4::get(int row, int col) const {
    return data[col * 4 + row];
}

void Mat4::set(int row, int col, double value) {
    data[col * 4 + row] = value;
}

Vec3 Mat4::transformPoint(const Vec3& point) const {

}

Vec3 Mat4::transformDirection(const Vec3& direction) const {

}

Vec3 Mat4::transformNormal(const Vec3& normal) const {

}

static std::array<double, 16> zeros() {
    std::array<double, 16> output;
    output.fill(0);

    return output;
}

static std::array<double, 16> identity() {    
    std::array<double, 16> output = zeros();
    
    output[0] = 1;
    output[5] = 1;
    output[10] = 1;
    output[15] = 1;

    return output;
}