#pragma once
#include "GeometryObject.h"
#include "Point.h"

#include "Math.h"

class NURBSSurface : public GeometryObject
{
private:
	std::vector<PointPtr> handles;
	size_t n, m;
	std::vector<float> knotsU;
	std::vector<float> knotsV;
	std::vector<float> weights;
	int orderU;
	int orderV;
	olc::Pixel color2;

public:
	std::vector<PointPtr>
		getHandles() {
		return handles;
	}

	NURBSSurface(std::vector<PointPtr> h, size_t n, std::vector<float> ku, std::vector<float> kv, int p, int q) {
		handles = h;
		this->n = n;
		m = h.size() / n;
		knotsU = ku;
		knotsV = kv;
		orderU = p;
		orderV = q;
		for (size_t i = 0; i < handles.size(); i++) {
			weights.push_back(1);
		}

		color = olc::RED;
		color2 = olc::GREEN;
	}

	NURBSSurface(std::vector<PointPtr> h, size_t n, std::vector<float> ku, std::vector<float> kv, std::vector<float> w, int p, int q) {
		handles = h;
		this->n = n;
		m = h.size() / n;
		knotsU = ku;
		knotsV = kv;
		orderU = p;
		orderV = q;
		weights = w;
		if (weights.size() != handles.size()) {
			std::cerr << "weights.size() != handles.size()" << std::endl;
			exit(1);
		}

		color = olc::RED;
		color2 = olc::GREEN;
	}

	void drawYourself(olc::PixelGameEngine& screen, Transform& transform) override {
		for (float u = knotsU.front(); u <= knotsU.back(); u += 1 / 16.0) {
			auto A = evaluate(u, 0);
			auto B = A;
			for (float t = knotsV.front(); t <= knotsV.back(); t += 0.01) {
				B = A;
				A = evaluate(u, t);
				screen.DrawLine(transform.WorldToScreen(A), transform.WorldToScreen(B), color);
			}

		}
		for (float v = knotsV.front(); v <= knotsV.back(); v += 1 / 16.0) {
			auto A = evaluate(0, v);
			auto B = A;
			for (float t = knotsU.front(); t <= knotsU.back(); t += 0.01) {
				B = A;
				A = evaluate(t, v);
				screen.DrawLine(transform.WorldToScreen(A), transform.WorldToScreen(B), color2);
			}

		}
	}

	olc::vf3d evaluate(float u, float v) {
		olc::vf3d sum = { 0, 0 };
		for (size_t i = 0; i < n*m; i++) {
			sum += handles[i]->pos * R(i, orderU, orderV, u, v);
		}
		return sum;
	}

	float R(size_t i, size_t p, size_t q, float u, float v) {
		float sum = 0;
		for (size_t k = 0; k < n; k++)
			for (size_t l = 0; l < m; l++)
				sum += N(k, p, u, knotsU) * N(l, q, v, knotsV) * weights[i];
		return N(i%n, p, u, knotsU) * N(i/n, q, v, knotsV) * weights[i] / sum;
	}

	float N(size_t i, size_t p, float u, vector<float>& knots) {
		if (p == 0) {
			return (knots[i] <= u && u < knots[i + 1]);
		}
		return (save_division(u - knots[i], knots[i + p] - knots[i]) * N(i, p - 1, u, knots) +
			save_division(knots[i + p + 1] - u, knots[i + p + 1] - knots[i + 1]) * N(i + 1, p - 1, u, knots));
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

typedef std::shared_ptr<NURBSSurface> NURBSSurfacePtr;
