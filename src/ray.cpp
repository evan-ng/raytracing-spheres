#include "..\include\colour.h"
#include "..\include\coordinates.h"
#include "..\include\light.h"
#include "..\include\ray.h"
#include "..\include\point3.h"
#include "..\include\sphere.h"
#include "..\include\vec3.h"

#include <limits>
#include <utility>
#include <vector>

const Colour BACKGROUND_COLOUR = Colour(0, 0, 0);

Colour trace_ray (const Ray& ray, double t_min, double t_max, 
                  const std::vector<Sphere*>& spheres, const std::vector<Light*>& lights)
{
    double t_hit;
    Sphere* sphere_hit = closest_ray_sphere_intersect(ray, t_min, t_max, spheres, t_hit);
    if (sphere_hit == NULL)
        return BACKGROUND_COLOUR;
    
    Vec3 hit_point = Vec3(ray.origin) + (t_hit * ray.direction);
    Vec3 normal = hit_point - Vec3(sphere_hit->center);
    normal.normalize();
    return sphere_hit->colour * light_intensity(hit_point.p, normal, lights);
}

Sphere* closest_ray_sphere_intersect (const Ray& ray, double t_min, double t_max, 
                                      const std::vector<Sphere*>& spheres, double& t)
{   
    t = t_max;
    Sphere* curr_sphere = nullptr;

    for (auto it = spheres.begin(); it != spheres.end(); ++it) {
        auto t_solutions = ray_sphere_intersects(ray, *it);

        if (t_solutions.first < t && t_solutions.first > t_min)
            t = t_solutions.first;
        else if (t_solutions.second < t && t_solutions.second > t_min)
            t = t_solutions.second;
        else
            continue;

        curr_sphere = *it;
    }

    return curr_sphere;
}

std::pair <double, double> ray_sphere_intersects (const Ray& ray, 
                                                  const Sphere* sphere)
{
    // vector from center of sphere to camera point (ray origin)
    Vec3 cent_to_cam = Vec3(ray.origin - sphere->center);

    double a, b, c; // parameters for quadratic formula
    a = dot(ray.direction, ray.direction);
    b = 2 * dot(cent_to_cam, ray.direction);
    c = dot(cent_to_cam, cent_to_cam) - sphere->radius * sphere->radius;

    return quadratic_formula(a, b, c);
}

std::pair <double, double> quadratic_formula (double a, double b, double c)
{
    double inf = std::numeric_limits<double>::infinity();
    std::pair <double, double> solution(inf, inf);

    double discriminant = b*b - 4*a*c;

    // negative discriminant has no real solution (left as inf)
    if (discriminant >= 0) {
        solution.first = ( -b - sqrt(discriminant) ) / (2 * a);
        solution.second = ( -b + sqrt(discriminant) ) / (2 * a);
    }

    // ensure the first value in the pair is the smallest value
    if (solution.first > solution.second) {
        double temp = solution.first;
        solution.first = solution.second;
        solution.second = temp;
    }
    
    return solution;
}