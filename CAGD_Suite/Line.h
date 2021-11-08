#pragma once
#include "GeometryObject.h"
#include "Point.h"

class Line : public GeometryObject
{
private:
	PointPtr A;
	PointPtr B;
public:
	Line(PointPtr a, PointPtr b);
	Line(PointPtr a, PointPtr b, olc::Pixel color);

	void drawYourself(olc::PixelGameEngine& screen, Transform& transform) override {
		auto a = transform.WorldToScreen(A->pos);
		auto b = transform.WorldToScreen(B->pos);
		screen.DrawLine(a, b, color);
	}

	std::vector<GeometryObjPtr> getExports() override {
		return {A, B};
	}

};

typedef std::shared_ptr<Line> LinePtr;
