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
	//Point(olc::vf2d x);
	Point(float x, float y, olc::Pixel color);
	//Point(olc::vf2d x, olc::Pixel color);
	Point(float x, float y, std::string name);
	//Point(olc::vf2d x, std::string name);
	Point(float x, float y, olc::Pixel color, std::string name);
	//Point(olc::vf2d x, olc::Pixel color, std::string name);

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
		pos = transform.ScreenToWorld(mousePos);
	}


};

typedef std::shared_ptr<Point>  PointPtr;

