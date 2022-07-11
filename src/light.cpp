#include "..\include\colour.h"
#include "..\include\coordinates.h"
#include "..\include\light.h"
#include "..\include\ray.h"
#include "..\include\point3.h"
#include "..\include\sphere.h"
#include "..\include\vec3.h"

#include <utility>
#include <vector>

double light_intensity (const Point3& sphere_point, const Vec3& normal, 
                        const std::vector<Light*>& lights)
{
    double i = 0.0;

    for (auto it = lights.begin(); it != lights.end(); ++it) {
        if ((*it)->type == ambient) {
            i += (*it)->intensity;
        }
        else {
            Vec3 light_dir;

            if ((*it)->type == point)
                light_dir = Vec3( (*it)->position - sphere_point );
            else
                light_dir = (*it)->direction;

            double n_dot_l = dot(normal, light_dir);
            if (n_dot_l > 0)
                i += (*it)->intensity * n_dot_l / (normal.length() + light_dir.length());

        }
    }

    return i;
}