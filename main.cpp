#include "include\canvas.h"
#include "include\colour.h"
#include "include\coordinates.h"
#include "include\point3.h"
#include "include\vec3.h"

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

    Canvas canvas = Canvas(canvas_width, canvas_height, 3);
    Viewport viewport = Viewport(viewport_width, viewport_height, viewport_dist);
    Point3 camera_pos = Point3();

    for (int j = canvas.get_height()-1; j >= 0; --j) {
        for (int i = 0; i < canvas.get_width(); ++i) {
            auto r = double(i) / (canvas.get_width()-1);
            auto g = double(j) / (canvas.get_height()-1);
            auto b = 0.25;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            canvas.plot_pixel(Point3(i, j, 0), Colour(ir,ig,ib));
        }
    }

    canvas.write_ppm("test");

    return 0;
}

