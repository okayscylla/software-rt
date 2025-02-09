#include "math/vec3.h"
#include <iostream>

int main() {
    Vec3 a(1.0, 2.0, 3.0);
    Vec3 b(4.0, 5.0, 6.0);

    std::cout << "Dot product: " << a.dot(b) << "\n";

    return 0;
}