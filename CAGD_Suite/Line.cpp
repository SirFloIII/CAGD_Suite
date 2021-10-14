#include "Line.h"

Line::Line(PointPtr a, PointPtr b)
{
	A = a;
	B = b;
}

Line::Line(PointPtr a, PointPtr b, olc::Pixel color)
{
	A = a;
	B = b;
	this->color = color;
}
