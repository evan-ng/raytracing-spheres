#include "include\canvas.h"
#include "include\colour.h"
#include "include\coordinates.h"
#include "include\light.h"
#include "include\point3.h"
#include "include\ray.h"
#include "include\sphere.h"
#include "include\vec3.h"
#include "include\viewport.h"

#include <limits>
#include <string>
#include <utility>
#include <vector>
#include <iostream>

const double T_MIN = 1.0;
const double T_MAX = std::numeric_limits<double>::infinity();

int main(int argc, char *argv[])
{
    // constants for the canvas
    const int canvas_width = 256;
    const int canvas_height = 256;
    // constants for the viewport
    const int viewport_width = 1;
    const int viewport_height = 1;
    const int viewport_dist = 1;

    // initialize scene objects
    Canvas canvas = Canvas(canvas_width, canvas_height, 3);
    Viewport viewport = Viewport(viewport_width, viewport_height, viewport_dist);
    Point3 camera_pos = Point3(0, 0, 0);

    std::vector<Sphere*> spheres;
    spheres.push_back( new Sphere(Point3(3, -1, 8), 1.0, Colour(255, 0, 0), 0, 0.05) ); // red
    spheres.push_back( new Sphere(Point3(0, 0, 3.5), 1.0, Colour(0, 255, 0), 1000, 0.5) );  // green
    spheres.push_back( new Sphere(Point3(1, 0.5, 3), 0.5, Colour(0, 255, 0), 1000, 0.9) );  // green
    spheres.push_back( new Sphere(Point3(-2, 1, 5), 1.0, Colour(0, 0, 255), 400, 0.25) ); // blue

    std::vector<Light*> lights;
    lights.push_back( new Light(ambient, 0.1) );
    lights.push_back( new Light(point, 0.6, Point3(-3, -5, 2)) );
    lights.push_back( new Light(directional, 0.3, Vec3(-1, -7, 1)) );

    // draw spheres
    for (int y = 0; y < canvas.get_height(); ++y) {
        for (int x = 0; x < canvas.get_width(); ++x) {
            // determine ray direction
            Point3 screen_pos = Point3(x, y, 0);
            Point3 canv_cord = screen_to_canvas(canvas, screen_pos);
            Vec3 ray_dir = Vec3(canvas_to_viewport(canvas, viewport, canv_cord));

            Ray ray = Ray(camera_pos, ray_dir);
            Colour colour = trace_ray(ray, T_MIN, T_MAX, spheres, lights);
            canvas.plot_pixel(screen_pos, colour);
        }
    }

    // write the ppm image file from the canvas data
    canvas.write_ppm("test");

    // free allocated sphere and light objects
    for (auto it = spheres.begin(); it != spheres.end(); ++it)
        delete *it;
    for (auto it = lights.begin(); it != lights.end(); ++it)
        delete *it;

    return 0;
}

