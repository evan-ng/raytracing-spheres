#include "..\include\colour.h"

Colour::Colour() : r{0}, g{0}, b{0} {}

Colour::Colour(int r0, int g0, int b0) 
{
    bound(r0, g0, b0);
}

Colour::Colour(unsigned char r0, unsigned char g0, unsigned char b0) : 
        r{r0}, g{g0}, b{b0} {}

Colour& Colour::operator+= (const Colour& c)
{
    bound(r + c.r, g + c.g, b + c.b);
}

Colour& Colour::operator*= (const double& k)
{
    bound(k * r, k * g, k * b);
}

Colour operator+ (const Colour& c1, const Colour& c2) {
    Colour c = Colour();
    c.bound(c1.r + c2.r, c1.g + c2.g, c1.b + c2.b);
    return c;
}

Colour operator* (const double& k, const Colour& c) {
    Colour c_new = Colour();
    c_new.bound(k * c.r, k * c.g, k * c.b);
    return c_new;
}

Colour operator* (const Colour& c, const double& k) {
    return k * c;
}

void Colour::bound(int r0, int g0, int b0) {
    r = (r0 > rgb_limit) ? rgb_limit : ((r0 < 0) ? 0 : r0);
    g = (g0 > rgb_limit) ? rgb_limit : ((g0 < 0) ? 0 : g0);
    b = (b0 > rgb_limit) ? rgb_limit : ((b0 < 0) ? 0 : b0);
}

// sets c to r, g, b if they are less than 256, otherwise sets to 255
void bound_colour(Colour& c, int r, int g, int b) 
{
    c.bound(r, g, b);
}