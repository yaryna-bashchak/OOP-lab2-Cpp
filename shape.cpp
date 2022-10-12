#include "shape.h"

/*Shape::Shape(Shape* p[])
{
	pcshape[3] = p[3];
}*/

void Shape::Set(long x1 = 0, long y1 = 0, long x2 = 0, long y2 = 0)
{
	xs1 = x1;
	ys1 = y1;
	xs2 = x2;
	ys2 = y2;
}