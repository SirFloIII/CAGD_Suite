#pragma once
#include "GeometryObject.h"
#include "Point.h"

#include "Math.h"

class NURBS : public GeometryObject
{
private:
	std::vector<PointPtr> handles;
	std::vector<float> knots;
	std::vector<float> weights;
	int order;

public:
	std::vector<PointPtr>
		getHandles() {
		return handles;
	}
	
	NURBS(std::vector<PointPtr> h, std::vector<float> k, int p) {
		handles = h;
		knots = k;
		order = p;
		for (size_t i = 0; i < handles.size(); i++) {
			weights.push_back(1);
		}

		color = olc::RED;
	}

	NURBS(std::vector<PointPtr> h, std::vector<float> k, std::vector<float> w, int p) {
		handles = h;
		knots = k;
		order = p;
		weights = w;

		if (weights.size() != handles.size()) {
			std::cerr << "weights.size() != handles.size()" << std::endl;
			exit(1);
		}

		color = olc::RED;
	}

	void drawYourself(olc::PixelGameEngine& screen, Transform& transform) override {
		auto A = evaluate(knots.front());
		auto B = A;
		for (float t = knots.front(); t <= knots.back(); t += 0.01) {
			A = evaluate(t);
			screen.DrawLine(transform.WorldToScreen(A), transform.WorldToScreen(B), color);
			B = A;
		}
	}

	olc::vf3d evaluate(float t) {
		size_t n = handles.size();
		olc::vf3d sum = {0, 0};
		float rsum = Rsum(order, t);
		for (size_t i = 0; i < n; i++) {
			sum += handles[i]->pos * R(i, order, t, rsum);
		}
		return sum;
	}

	float Rsum(size_t j, float u) {
		float sum = 0;
		for (size_t k = 0; k < handles.size(); k++)
			sum += N(k, j, u) * weights[k];
		return sum;
	}

	float R(size_t i, size_t j, float u, float sum) {
		return N(i, j, u) * weights[i] / sum;
	}

	float N(size_t i, size_t p, float u) {
		if (p == 0) {
			return (knots[i] <= u && u < knots[i + 1]);
		}
		return (save_division(u - knots[i], knots[i + p] - knots[i]) * N(i, p - 1, u) +
			save_division(knots[i + p + 1] - u, knots[i + p + 1] - knots[i + 1]) * N(i + 1, p - 1, u));
	}

	float save_division(float a, float b) {
		if (b == 0) return 1;
		return a / b;
	}


	std::vector<GeometryObjPtr> getExports() override {
		std::vector<GeometryObjPtr> out;
		for (auto p : handles) {
			out.push_back(p);
		}
		return out;
	}
};

typedef std::shared_ptr<NURBS> NURBSPtr;
