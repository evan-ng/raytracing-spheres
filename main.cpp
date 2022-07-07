#include "include\canvas.h"
#include "include\colour.h"
#include "include\coordinates.h"
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
    spheres.push_back( new Sphere(Point3(2, -1, 16), 1, Colour(255, 0, 0)) ); // red
    spheres.push_back( new Sphere(Point3(0, 0, 8), 1, Colour(0, 255, 0)) );  // green
    spheres.push_back( new Sphere(Point3(-2, 1, 12), 1, Colour(0, 0, 255)) ); // blue

    // draw spheres
    for (int y = 0; y < canvas.get_height(); ++y) {
        for (int x = 0; x < canvas.get_width(); ++x) {
            // determine ray direction
            Point3 screen_pos = Point3(x, y, 0);
            Point3 canv_cord = screen_to_canvas(canvas, screen_pos);
            Vec3 ray_dir = Vec3(canvas_to_viewport(canvas, viewport, canv_cord));

            Ray ray = Ray(camera_pos, ray_dir);
            Colour colour = trace_ray(ray, T_MIN, T_MAX, spheres);
            canvas.plot_pixel(screen_pos, colour);
        }
    }

    canvas.write_ppm("test");

    return 0;
}

