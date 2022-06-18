#pragma once

struct Colour {
    unsigned char r, g, b;

    Colour() : r{0}, g{0}, b{0} {}
    Colour(unsigned char r0, unsigned char g0, unsigned char b0) : 
        r{r0}, g{g0}, b{b0} {}
};