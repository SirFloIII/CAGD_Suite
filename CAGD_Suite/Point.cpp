#include "Point.h"

Point::Point(float x, float y)
{
	pos = { x, y };
	color = olc::WHITE;
}

Point::Point(olc::vf2d x)
{
	pos = x;
	color = olc::WHITE;
}

Point::Point(float x, float y, olc::Pixel color)
{
	pos = { x, y };
	this->color = color;
}

Point::Point(olc::vf2d x, olc::Pixel color)
{
	pos = x;
	this->color = color;
}

Point::Point(float x, float y, std::string name)
{
	pos = { x, y };
	color = olc::WHITE;
	this->name = name;
}

Point::Point(olc::vf2d x, std::string name)
{
	pos = x;
	color = olc::WHITE;
	this->name = name;
}

Point::Point(float x, float y, olc::Pixel color, std::string name)
{
	pos = { x, y };
	this->color = color;
	this->name = name;
}

Point::Point(olc::vf2d x, olc::Pixel color, std::string name)
{
	pos = x;
	this->color = color;
	this->name = name;
}
