#include "math/mat4.h"
#include <iostream>
#include <ostream>

// TODO: get rid of whatever nonsense is happening here lol

int main() {
    Mat4 matrix;

    std::cout << matrix.determinant() << std::endl;
    return 0;
}