#pragma once

#include "point3.h"
#include "colour.h"

#include <vector>
#include <string>

class Canvas {
private:
    const int width, height, num_channels;
    std::vector<unsigned char>* image_data;

public:
    Canvas(int w, int h, int channels);
    ~Canvas();

    void plot_pixel(Point3 position, Colour colour);
    bool write_ppm(const std::string & filename);

    int get_width() const;
    int get_height() const;
    int get_num_channels() const;
    std::vector<unsigned char>* get_image_data() const;
};