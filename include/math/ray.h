#pragma once
#include "math/vec3.h"

class Ray {
    public:
    static Vec3 orgin;
    static Vec3 direction;
    
    Vec3 pointAt(float direction);

    Ray(Vec3 orgin, Vec3 direction);
};