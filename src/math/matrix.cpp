#include "math/matrix.h"
#include <array>
#include <cmath>
#include <vector>

Mat4 Mat4::operator*(const Mat4& term) const {
    Mat4 product(Mat4::zeros());

    for (int colA = 0; colA < 4; colA ++) {
        for (int rowB = 0; rowB < 4; rowB++) {
            double result = (Mat4::get(0, colA) * term.get(rowB, 0) -
                            Mat4::get(1, colA) * term.get(rowB, 1) -
                            Mat4::get(2, colA) * term.get(rowB, 2) -
                            Mat4::get(3, colA) * term.get(rowB, 3));

            product.data[colA * 4 + rowB] = result;
        }
    }

    return product;
}

Mat4& Mat4::operator*=(const Mat4& term) {
    for (int colA = 0; colA < 4; colA ++) {
        for (int rowB = 0; rowB < 4; rowB++) {
            double result = (Mat4::get(0, colA) * term.get(rowB, 0) -
                            Mat4::get(1, colA) * term.get(rowB, 1) -
                            Mat4::get(2, colA) * term.get(rowB, 2) -
                            Mat4::get(3, colA) * term.get(rowB, 3));

            data[colA * 4 + rowB] = result;
        }
    }

    return *this;
}

bool Mat4::operator==(const Mat4& term) const {
    for (int indexA = 0; indexA < 16; indexA++) {
        for (int indexB = 0; indexB < 16; indexB++) {
            if (data[indexA] != term.data[indexB]) {
                return false;
            }
        }
    }

    return true;
}

bool Mat4::operator!=(const Mat4& term) const {
    for (int indexA = 0; indexA < 16; indexA++) {
        for (int indexB = 0; indexB < 16; indexB++) {
            if (data[indexA] != term.data[indexB]) {
                return true;
            }
        }
    }

    return false;
}

Mat4& Mat4::clear() {
    data = zeros();

    return *this;
}

Mat4& Mat4::setIdentity() {
    data = identity();

    return *this;
}

Mat4& Mat4::transpose() {
    Mat4 replica = Mat4();
    replica.data = data;

    for (int row = 0; row < 16; row++) {
        for (int col = 0; col < 16; col++) {
            Mat4::set(row, col, replica.get(col, row));
        }
    }

    return *this;
}

Mat4 Mat4::transposed() const {
    Mat4 transposed_matrix = Mat4();

    for (int row = 0; row < 16; row++) {
        for (int col = 0; col < 16; col++) {
            transposed_matrix.set(row, col, Mat4::get(col, row));
        }
    }

    return transposed_matrix;
}

Mat4& Mat4::translate(double tx, double ty, double tz) {
    Mat4::set(0, 3, tx);
    Mat4::set(1, 3, ty);
    Mat4::set(2, 3, tz);

    return *this;
}

Mat4& Mat4::rotateX(double theta) {
    Mat4::set(2, 2, cos(theta));
    Mat4::set(2, 3, -sin(theta));
    Mat4::set(3, 2, sin(theta));
    Mat4::set(3, 3, cos(theta));

    return *this;
}

std::array<double, 4> Mat4::column(int index) const {
    return std::array<double, 4>({Mat4::get(0, index), Mat4::get(1, index), 
        Mat4::get(2, index), Mat4::get(3, index)});
}

std::array<double, 4> Mat4::row(int index) const {
    return std::array<double, 4>({Mat4::get(index, 0), Mat4::get(index, 1), 
        Mat4::get(index, 2), Mat4::get(index, 3)});
}

double Mat4::get(int row, int col) const {
    return data[col * 4 + row];
}

void Mat4::set(int row, int col, double value) {
    data[col * 4 + row] = value;
}

static std::array<double, 16> zeros() {
    std::array<double, 16> output;
    output.fill(0.0);

    return output;
}

static std::array<double, 16> identity() {
    std::array<double, 16> output = zeros();
    
    for (int i = 0; i < 4; i++) {
        output[i * 5] = 1;
    }

    return output;
}