#include "..\include\canvas.h"
#include "..\include\coordinates.h"
#include "..\include\point3.h"
#include "..\include\vec3.h"

Point3 screen_to_canvas (const Canvas& canvas, const Point3& p)
{
    return Point3(p.x - canvas.get_width()/2, 
                  canvas.get_height()/2 - p.y, 
                  p.z);
}

Vec3 screen_to_canvas (const Canvas& canvas, const Vec3& v) 
{
    return Vec3( screen_to_canvas(canvas, v.p) );
}

Point3 canvas_to_screen (const Canvas& canvas, const Point3& p)
{
    return Point3(p.x + canvas.get_width()/2, 
                  canvas.get_height()/2 - p.y, 
                  p.z);
}

Vec3 canvas_to_screen (const Canvas& canvas, const Vec3& v)
{
    return Vec3( canvas_to_screen(canvas, v.p) );
}
