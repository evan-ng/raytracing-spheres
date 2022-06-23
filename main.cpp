#include "include\canvas.h"
#include "include\colour.h"
#include "include\coordinates.h"
#include "include\sphere.h"
#include "include\point3.h"
#include "include\vec3.h"
#include "include\viewport.h"

#include <string>

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

    Sphere red_sphere = Sphere(Point3(2, -1, 4), 1, Colour(255, 0, 0));
    Sphere green_sphere = Sphere(Point3(0, 0, 3), 1, Colour(0, 255, 0));
    Sphere blue_sphere = Sphere(Point3(-2, 1, 2), 1, Colour(0, 0, 255));

    // draw black background
    for (int y = 0; y < canvas.get_height(); ++y) {
        for (int x = 0; x < canvas.get_width(); ++x) {
            canvas.plot_pixel(Point3(x, y, 0), Colour(0, 0, 0));
        }
    }

    canvas.write_ppm("test");

    return 0;
}

