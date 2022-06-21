#pragma once

#include "canvas.h"
#include "point3.h"
#include "vec3.h"

// converts screen coordinates (origin at upper-left corner) to
// canvas coordinates (origin at center)
Point3 screen_to_canvas (const Canvas& canvas, const Point3& p);
Vec3 screen_to_canvas (const Canvas& canvas, const Vec3& v);

// converts canvas coordinates (origin at center) to 
// screen coordinates (origin at upper-left corner)
Point3 canvas_to_screen (const Canvas& canvas, const Point3& p);
Vec3 canvas_to_screen (const Canvas& canvas, const Vec3& v);