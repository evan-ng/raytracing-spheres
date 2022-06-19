#include "include\canvas.h"
#include "include\colour.h"
#include "include\point3.h"
#include "include\vec3.h"

#include <string>

int main(int argc, char *argv[])
{
    const int width = 256;
    const int height = 256;

    Canvas canvas = Canvas(width, height, 3);

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

