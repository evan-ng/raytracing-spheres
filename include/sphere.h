#pragma once

#include "colour.h"
#include "point3.h"

struct Sphere {
    Point3 center;
    double radius;
    Colour colour;
    int specular;

    Sphere(Point3 cent, double rad, Colour col, int spec) :
        center{cent}, radius{rad}, colour{col}, specular{spec} {}
};
