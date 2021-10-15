#pragma once
#include "GeometryObject.h"
#include "Math.h"


class BernsteinPolynom : public GeometryObject
{
public:
	int n, i;
	BernsteinPolynom(int n, int i) {
		this->n = n;
		this->i = i;
		this->color = olc::RED;
	}
	BernsteinPolynom(int n, int i, olc::Pixel color) {
		this->n = n;
		this->i = i;
		this->color = color;
	}

	void drawYourself(olc::PixelGameEngine& screen, Transform& transform) override {
		olc::vi2d A, B;
		A = transform.WorldToScreen({ 0, Bernstein(n, i, 0) });
		for (float t = 0; t <= 1; t += 0.01) {
			B = transform.WorldToScreen({ t, Bernstein(n, i, t) });
			screen.DrawLine(A, B, color);
			A = B;
		}
	}


};

typedef std::shared_ptr<BernsteinPolynom> BernsteinPolynomPtr;