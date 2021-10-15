#include "Circle.h"

Circle::Circle(PointPtr center, float radius)
{
	this->center = center;
	this->radius = radius;
	this->color = olc::GREY;
}

Circle::Circle(PointPtr center, float radius, olc::Pixel color)
{
	this->center = center;
	this->radius = radius;
	this->color = color;
}
