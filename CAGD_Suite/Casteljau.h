#pragma once
#include "GeometryObject.h"
#include "Point.h"

#include "Math.h"

class Casteljau : public GeometryObject
{
private:
	std::vector<PointPtr> handles;

public:
	float t = 0.5;
	std::vector<olc::Pixel> colors = {
		olc::BLUE,
		olc::CYAN,
		olc::GREEN,
		olc::YELLOW,
		olc::RED,
		olc::MAGENTA,
	};


	Casteljau(std::vector<PointPtr> h) {
		handles = h;
		color = olc::RED;
	}

	void drawYourself(olc::PixelGameEngine& screen, Transform& transform) override {
		std::vector<olc::vf2d> points;
		for (auto point : handles) points.push_back(point->pos);

		for (size_t i = 0; i <= handles.size(); i++) {
			for (size_t j = 1; j < handles.size() - i; j++) {
				screen.DrawLine(transform.WorldToScreen(points[j-1]),
								transform.WorldToScreen(points[j]), colors[i%6]);
				points[j-1] = (1 - t) * points[j - 1] + t * points[j];
			}
		}
		
		
		
		
		auto A = evaluate(0);
		auto B = A;
		for (float t = 0; t <= 1; t += 0.01) {
			B = A;
			A = evaluate(t);
			screen.DrawLine(transform.WorldToScreen(A), transform.WorldToScreen(B), color);
		}
	}

	olc::vf2d evaluate(float t) {
		std::vector<olc::vf2d> pos;
		for (auto point : handles) pos.push_back(point->pos);
		return deCasteljau(t, pos);
	}

};

typedef std::shared_ptr<Casteljau> CasteljauPtr;
