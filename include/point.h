#pragma once

struct Point3 {
    double x, y, z;

    Point3() : x{0}, y{0}, z{0} {}
    Point3(double x0, double y0, double z0) : x{x0}, y{y0}, z{z0} {}
};