#pragma once

#include "colour.h"
#include "point3.h"
#include "sphere.h"
#include "vec3.h"

#include <utility>
#include <vector>

struct Ray {
    Point3 origin;
    Vec3 direction;

    Ray(const Point3& orig, const Vec3& dir) : origin{orig}, direction{dir} {}
};

Colour trace_ray (const Ray& ray, int t_min, int t_max, 
                  const std::vector<Sphere*>& spheres);

Sphere* closest_ray_sphere_intersect (const Ray& ray, int t_min, int t_max, 
                                      const std::vector<Sphere*>& spheres, int& t);

std::pair <int, int> ray_sphere_intersects (const Ray& ray, const Sphere* sphere);

double light_intensity (const Point3& point, const Vec3& normal, 
                        const Vec3& point_to_camera, double specular_exponent);