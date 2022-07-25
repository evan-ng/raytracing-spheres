#pragma once

#include "colour.h"
#include "point3.h"
#include "vec3.h"

enum LightType { ambient, point, directional };

struct Light {
    LightType type;
    double intensity;
    Point3 position;
    Vec3 direction;

    // constructor for ambient light
    Light(LightType light_type, double light_intensity) :
        type{light_type}, intensity{light_intensity} {}

    // constructor for point light
    Light(LightType light_type, double light_intensity, Point3 pos) :
        type{light_type}, intensity{light_intensity}, position{pos} {}

    // constructor for directional light
    Light(LightType light_type, double light_intensity, Vec3 dir) :
        type{light_type}, intensity{light_intensity}, direction{dir} {}
};

double light_intensity (const Point3& sphere_point, const Vec3& normal, 
                        const std::vector<Light*>& lights);