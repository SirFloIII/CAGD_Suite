#pragma once
#include "GeometryObject.h"
#include "Point.h"

class Circle : public GeometryObject
{
private:
	PointPtr center;
	float radius;

public:
	Circle(PointPtr center, float radius);
	Circle(PointPtr center, float radius, olc::Pixel color);

	void drawYourself(olc::PixelGameEngine& screen, Transform& transform) override {
		screen.DrawCircle(transform.WorldToScreen(center->pos),
			transform.fScale * radius, color);
	}
};

typedef std::shared_ptr<Circle> CirclePtr;
