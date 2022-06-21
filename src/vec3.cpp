#include "..\include\point3.h"
#include "..\include\vec3.h"

#include <cmath>
#include <vector>

Vec3::Vec3() : p{0, 0, 0} {}
Vec3::Vec3(Point3 p0) : p{p0.x, p0.y, p0.z} {}
Vec3::Vec3(double x, double y, double z) : p{x, y, z} {}

Vec3 Vec3::operator-() const 
{
    return Vec3(-p.x, -p.y, -p.z);
}

Vec3& Vec3::operator+= (const Vec3 &v) 
{
    p.x += v.p.x;
    p.y += v.p.y;
    p.z += v.p.z;
    return (*this);
}

Vec3& Vec3::operator-= (const Vec3 &v) 
{
    return (*this) += -v;
}

Vec3& Vec3::operator*= (const double &k) 
{
    p.x *= k;
    p.y *= k;
    p.z *= k;
    return (*this);
}

Vec3& Vec3::operator/= (const double &k) 
{
    return (*this) *= 1/k;
}

double Vec3::square_sum() const 
{
    return (p.x * p.x + p.y * p.y + p.z * p.z);
}

double Vec3::length() const 
{
    return std::sqrt(square_sum());
}

Vec3& Vec3::normalize() 
{
    return (*this) /= length();
}

Vec3 operator+ (const Vec3& u, const Vec3& v) 
{
    return Vec3(u.p.x + v.p.x, u.p.y + v.p.y, u.p.z + v.p.z);
}

Vec3 operator- (const Vec3& u, const Vec3& v)
{
    return Vec3(u.p.x - v.p.x, u.p.y - v.p.y, u.p.z - v.p.z);
}

Vec3 operator* (const Vec3& v, const double& k)
{
    return Vec3(k * v.p.x, k * v.p.y, k * v.p.z);
}

Vec3 operator* (const double& k, const Vec3& v)
{
    return Vec3(k * v.p.x, k * v.p.y, k * v.p.z);
}

Vec3 operator/ (const Vec3& v, const double& k)
{
    return (1/k) * v;
}

double dot(const Vec3& u, const Vec3& v)
{
    return (u.p.x * v.p.x + u.p.y * v.p.y + u.p.z * v.p.z);
}

Vec3 cross(const Vec3& u, const Vec3& v)
{
    return Vec3(u.p.y * v.p.z - u.p.z * v.p.x,
                u.p.z * v.p.x - u.p.x * v.p.z,
                u.p.x * v.p.y - u.p.y * v.p.x);
}

Vec3 unit(Vec3 v) 
{
    return v.normalize();
}