#pragma once
#include "GeometryObject.h"
#include "Point.h"

#include "Math.h"

class BezierSurface : public GeometryObject
{
private:
	std::vector<PointPtr> handles;
	size_t n, m;
	olc::Pixel color2;

public:
	std::vector<PointPtr> getHandles() {
		return handles;
	}

	BezierSurface(std::vector<PointPtr> h, size_t n) : BezierSurface(h, n, olc::RED, olc::GREEN) {}
	BezierSurface(std::vector<PointPtr> h, size_t n, olc::Pixel col) : BezierSurface(h, n, col, col) {}
	BezierSurface(std::vector<PointPtr> h, size_t n, olc::Pixel col, olc::Pixel col2) {
		handles = h;
		this->n = n;
		this->m = h.size() / n;
		if (n * m != h.size()) {
			cerr << "Beziersurface wrong size!" << endl;
			cerr << n << " doesn't divide " << h.size() << endl;
			exit(1);
		}

		color = col;
		color2 = col2;
	}

	void drawYourself(olc::PixelGameEngine& screen, Transform& transform) override {
		for (float u = 0; u <= 1.0; u += 1 / 16.0) {
			auto A = evaluate(u, 0);
			auto B = A;
			for (float t = 0; t <= 1; t += 0.01) {
				B = A;
				A = evaluate(u, t);
				screen.DrawLine(transform.WorldToScreen(A), transform.WorldToScreen(B), color);
			}

		}
		for (float v = 0; v <= 1.0; v += 1 / 16.0) {
			auto A = evaluate(0, v);
			auto B = A;
			for (float t = 0; t <= 1; t += 0.01) {
				B = A;
				A = evaluate(t, v);
				screen.DrawLine(transform.WorldToScreen(A), transform.WorldToScreen(B), color2);
			}

		}
	}

	olc::vf3d evaluate(float u, float v) {
		olc::vf3d out = { 0, 0, 0 };
		for (size_t i = 0; i < n * m; i++) {
			size_t j = i % n;
		    size_t k = i / n;
			out += Bernstein(n-1, j, u) * Bernstein(m-1, k, v) * handles[i]->pos;
		}
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

typedef std::shared_ptr<BezierSurface> BezierSurfacePtr;
