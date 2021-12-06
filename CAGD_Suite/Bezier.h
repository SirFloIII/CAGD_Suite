#pragma once
#include "GeometryObject.h"
#include "Point.h"

#include "Math.h"

class Bezier : public GeometryObject
{
private:
	std::vector<PointPtr> handles;

public:
	std::vector<PointPtr>
	getHandles() {
		return handles;
	}

	Bezier(std::vector<PointPtr> h) {
		handles = h;
		color = olc::RED;
	}

	Bezier(std::vector<PointPtr> h, olc::Pixel col) {
		handles = h;
		color = col;
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
		size_t n = handles.size() - 1;
		olc::vf2d out = { 0, 0 };
		for (size_t i = 0; i <= n; i++)
			out += Bernstein(n, i, t) * handles[i]->pos;
		return out;
	}

	std::vector<GeometryObjPtr> getExports() override {
		std::vector<GeometryObjPtr> out;
		for (auto p : handles) {
			out.push_back(p);
		}
		return out;
	}
};

typedef std::shared_ptr<Bezier> BezierPtr;
