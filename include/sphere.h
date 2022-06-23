#pragma once

#include "colour.h"
#include "point3.h"

struct Sphere {
    Point3 center;
    double radius;
    Colour colour;

    Sphere(Point3 cent, double rad, Colour col) :
        center{cent}, radius{rad}, colour{col} {}
};
