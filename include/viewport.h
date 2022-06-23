#pragma once

#include "point3.h"
#include "colour.h"

#include <vector>
#include <string>

class Viewport {
private:
    const int width, height, dist;

public:
    Viewport(int w, int h, int d);

    int get_width() const;
    int get_height() const;
    int get_dist() const;
};