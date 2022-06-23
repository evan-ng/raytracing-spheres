#include "..\include\viewport.h"

Viewport::Viewport(int w, int h, int d) : width{w}, height{h}, dist{d} {}

int Viewport::get_width() const
{
    return width;
}

int Viewport::get_height() const
{
    return height;
}

int Viewport::get_dist() const
{
    return dist;
}