#pragma once

#include "point3.h"

#include <cmath>

class Vec3 {
public:
    Point3 p;

    Vec3();
    Vec3(Point3 p0);
    Vec3(double p0, double p1, double p2);

    Vec3 operator-() const;
    Vec3& operator+= (const Vec3 &v);
    Vec3& operator-= (const Vec3 &v);
    Vec3& operator*= (const double &k);
    Vec3& operator/= (const double &k);

    double square_sum() const;
    double length() const;
    Vec3& normalize();
};

Vec3 operator+ (const Vec3& u, const Vec3& v);
Vec3 operator- (const Vec3& u, const Vec3& v);
Vec3 operator* (const Vec3& v, const double& k);
Vec3 operator* (const double& k, const Vec3& v);
Vec3 operator/ (const Vec3& v, const double& k);

double dot(const Vec3& u, const Vec3& v);
Vec3 cross(const Vec3& u, const Vec3& v);
Vec3 unit(Vec3 v);
