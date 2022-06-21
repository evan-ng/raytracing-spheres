#pragma once

const unsigned char rgb_limit = 255;

class Colour {
public:
    unsigned char r, g, b;

    Colour();
    Colour(int r0, int g0, int b0);
    Colour(unsigned char r0, unsigned char g0, unsigned char b0);

    Colour& operator+= (const Colour& c);
    Colour& operator*= (const double& k);

    friend Colour operator+ (const Colour& c1, const Colour& c2);
    friend Colour operator* (const double& k, const Colour& c);  
    friend Colour operator* (const Colour& c, const double& k);

    // sets c to r, g, b if they are less than 256, otherwise sets to 255
    friend void bound_colour(Colour& c, int r, int g, int b);  

private:
    void bound(int r, int g, int b);
};
