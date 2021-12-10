#include "Point.h"

Point::Point(float x, float y)
{
	pos = { x, y, 0 };
	color = olc::WHITE;
}

Point::Point(float x, float y, olc::Pixel color)
{
	pos = { x, y, 0 };
	this->color = color;
}

Point::Point(float x, float y, std::string name)
{
	pos = { x, y, 0 };
	color = olc::WHITE;
	this->name = name;
}

Point::Point(float x, float y, olc::Pixel color, std::string name)
{
	pos = { x, y, 0 };
	this->color = color;
	this->name = name;
}

Point::Point(float x, float y, float z)
{
	pos = { x, y, z };
	color = olc::WHITE;
}

Point::Point(float x, float y, float z, olc::Pixel color)
{
	pos = { x, y, z };
	this->color = color;
}

Point::Point(float x, float y, float z, std::string name)
{
	pos = { x, y, z };
	color = olc::WHITE;
	this->name = name;
}

Point::Point(float x, float y, float z, olc::Pixel color, std::string name)
{
	pos = { x, y, z };
	this->color = color;
	this->name = name;
}

