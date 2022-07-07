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

// Returns the colour of the sphere that a given ray hits first, or black
// if it hits nothing, within a given t range
Colour trace_ray (const Ray& ray, double t_min, double t_max, 
                  const std::vector<Sphere*>& spheres);

// Returns the sphere a ray hits first within a given t range
Sphere* closest_ray_sphere_intersect (const Ray& ray, double t_min, double t_max, 
                                      const std::vector<Sphere*>& spheres);

// Returns a pair of solutions for the intersection of a single ray and sphere
std::pair <double, double> ray_sphere_intersects (const Ray& ray, 
                                                  const Sphere* sphere);

// Parameters: a, b, c - parameters in equation ax^2 + bx + c = 0
// Returns pair of solutions with first being smallest
// If no solution, returns pair of infinity
std::pair <double, double> quadratic_formula (double a, double b, double c);

double light_intensity (const Point3& point, const Vec3& normal, 
                        const Vec3& point_to_camera, double specular_exponent);