#include "..\include\canvas.h"
#include "..\include\colour.h"
#include "..\include\point3.h"
#include "..\include\vec3.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

Canvas::Canvas(int w, int h, int channels) : 
    width{w}, height{h}, num_channels{channels} 
{
    image_data = new std::vector<unsigned char>();
    (*image_data).resize(w * h * channels, 0);
}

Canvas::~Canvas() 
{
    delete image_data;
    image_data = nullptr;
}

void Canvas::plot_pixel(Point3 position, Colour colour) 
{
    int index = 3 * (position.y * width + position.x);
    (*image_data)[index] = colour.r;
    (*image_data)[index + 1] = colour.b;
    (*image_data)[index + 2] = colour.g;
}

bool Canvas::write_ppm(const std::string & filename) 
{
    std::ofstream image;
    image.open(filename + ".ppm");

    if (image.fail()) {
        std::cout << "Unable to create " + filename + ".ppm" << std::endl;
        return false;
    }

    image << "P3" << std::endl;
    image << width << " " << height << std::endl;
    image << "255" << std::endl;

    for (auto pixel_part : *image_data) {
        image << pixel_part << " " << std::endl;
    }

    image.close();

    return true;
}

int Canvas::get_width() 
{
    return width;
}

int Canvas::get_height()
{
    return height;
}

int Canvas::get_num_channels()
{
    return num_channels;
}

std::vector<unsigned char>* Canvas::get_image_data()
{
    return image_data;
}