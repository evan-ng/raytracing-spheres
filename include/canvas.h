#pragma once

#include "point3.h"
#include "colour.h"

#include <vector>
#include <string>

class Canvas {
private:
    const int width, height, num_channels;
    std::vector<unsigned char> & image_data;

public:
    Canvas(int width, int height, int num_channels);
    ~Canvas();

    void plot_pixel(Point3 position, Colour colour);
    bool write_ppm(const std::string & filename);

    int get_width();
    int get_height();
    int get_num_channels();
};