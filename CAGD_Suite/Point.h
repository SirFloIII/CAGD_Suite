#pragma once
#include "olcPixelGameEngine.h"

#include "GeometryObject.h"


class Point : public GeometryObject
{
private:

public:
	olc::vf3d pos;
	std::string name = "";

	Point(float x, float y);
	Point(float x, float y, olc::Pixel color);
	Point(float x, float y, std::string name);
	Point(float x, float y, olc::Pixel color, std::string name);

	Point(float x, float y, float z);
	Point(float x, float y, float z, olc::Pixel color);
	Point(float x, float y, float z, std::string name);
	Point(float x, float y, float z, olc::Pixel color, std::string name);

	void drawYourself(olc::PixelGameEngine& screen, Transform& transform) override {
		auto scPos = transform.WorldToScreen(pos);
		screen.DrawCircle(scPos, 2, color);
		screen.DrawString(scPos + olc::vi2d(3,2), name);
	}
	bool getsGrabbed(olc::vi2d mousePos, Transform& transform) override {
		auto a = transform.WorldToScreen(pos) - mousePos;
		return (a.mag() <= 2);
	}
	void updatePosition(olc::vi2d mousePos, Transform& transform) override {		
		float z = transform.WorldToScreenDistance(pos);
		pos = transform.ScreenToWorld(mousePos, z);
	}


};

typedef std::shared_ptr<Point>  PointPtr;

