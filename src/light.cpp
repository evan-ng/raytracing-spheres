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

double light_intensity (const Point3& sphere_point, const Vec3& normal, 
                        const std::vector<Sphere*>& spheres,
                        const std::vector<Light*>& lights, 
                        const Vec3& obj_to_cam, int specular_exponent)
{
    double i = 0.0;

    for (auto it = lights.begin(); it != lights.end(); ++it) {
        if ((*it)->type == ambient) { // add ambient
            i += (*it)->intensity;
        } else { // add point and direction based on normals
            Vec3 light_dir;
            double t_min = 0.001, t_max;
            if ((*it)->type == point) {
                light_dir = Vec3( (*it)->position - sphere_point );
                t_max = 1;
            }
            else {
                light_dir = (*it)->direction;
                t_max = std::numeric_limits<double>::infinity();
            }

            // check shadow, if intersect, exclude diffuse and specular
            double shadow_t;
            Ray shadow_ray = Ray(sphere_point, light_dir);
            Sphere* shadow_sphere = closest_ray_sphere_intersect(shadow_ray, t_min, t_max, 
                                                                 spheres, shadow_t);
            if (shadow_sphere != NULL) {
                continue;
            }

            // diffuse reflection
            double n_dot_l = dot(normal, light_dir);
            if (n_dot_l > 0)
                i += (*it)->intensity * n_dot_l / (normal.length() + light_dir.length());

            // specular reflection
            if (specular_exponent > 0) {
                Vec3 reflected_ray = 2 * normal * dot(normal, light_dir) - light_dir;
                double r_dot_v = dot(reflected_ray, obj_to_cam);
                if (r_dot_v > 0) {
                    double base = r_dot_v/(reflected_ray.length() * obj_to_cam.length());
                    i += (*it)->intensity * pow(base, specular_exponent);
                }
            }   
        }
    }

    return i;
}