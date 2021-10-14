#pragma once
#include "GeometryObject.h"
#include "Point.h"

#include "Math.h"

class Bezier : public GeometryObject
{
private:
	std::vector<PointPtr> handles;

public:
	Bezier(std::vector<PointPtr> h) {
		handles = h;
		color = olc::RED;
	}

	void drawYourself(olc::PixelGameEngine& screen, Transform& transform) override {
		auto A = evaluate(0);
		auto B = A;
		for (float t = 0; t <= 1; t += 0.01) {
			B = A;
			A = evaluate(t);
			screen.DrawLine(transform.WorldToScreen(A), transform.WorldToScreen(B), color);
		}
	}

	olc::vf2d evaluate(float t) {
		int n = handles.size() - 1;
		olc::vf2d out = { 0, 0 };
		for (int i = 0; i <= n; i++)
			out += Bernstein(n, i, t) * handles[i]->pos;
		return out;
	}

};

typedef std::shared_ptr<Bezier> BezierPtr;
