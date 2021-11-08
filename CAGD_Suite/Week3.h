#pragma once
#include "ExerciseProblem.h"
#include "GeometryCollection.h"


#define ex_3_18
class BSP_3_18 : public ExerciseProblem
{
private:
	BezierPtr b;
	PointPtr A, B, C, S, V;
	LinePtr v;

public:
	std::vector<GeometryObjPtr> doSetup() override {
		description = "";

		return {
			b = std::make_shared<Bezier>(std::vector<PointPtr>({A = std::make_shared<Point>(0,0, "A"),
																B = std::make_shared<Point>(-1,2, "B"),
																C = std::make_shared<Point>(3,2, "C")})),
			S = std::make_shared<Point>(0,0, "S"),
			v = std::make_shared<Line>(B, V = std::make_shared<Point>(0, 0), olc::BLUE)
		};
	}

	void eachFrame(float dt) override {
		V->pos = 2.0 * (A->pos + C->pos) - 3.0 * B->pos;
		float AA = A->pos.dot(A->pos);
		float AB = A->pos.dot(B->pos);
		float AC = A->pos.dot(C->pos);
		float BB = B->pos.dot(B->pos);
		float BC = B->pos.dot(C->pos);
		float CC = C->pos.dot(C->pos);

		// d/dt <b'', b(t)> / 4 = coef_t * t + coef_1
		float coef_t = AA - 4 * AB + 2 * AC + 4 * BB - 4 * BC + CC;
		float coef_1 = -AA + 3 * AB - AC - 2 * BB + BC;
		float t = -coef_1 / coef_t;

		S->pos = b->evaluate(t);
	}

};


#define ex_3_21
class BSP_3_21 : public ExerciseProblem
{
private:
	BezierPtr b, b1, b2;
	SliderFloatPtr t;
public:
	std::vector<GeometryObjPtr> doSetup() override {
		description = "";

		return {
			b = std::make_shared<Bezier>(std::vector<PointPtr>({std::make_shared<Point>(0,0),
											 std::make_shared<Point>(-1,2),
											 std::make_shared<Point>(3,2),
											 std::make_shared<Point>(1,0)})),
			b1 = std::make_shared<Bezier>(std::vector<PointPtr>({std::make_shared<Point>(0,0, olc::GREEN),
											 std::make_shared<Point>(0,0, olc::GREEN),
											 std::make_shared<Point>(0,0, olc::GREEN),
											 std::make_shared<Point>(0,0, olc::GREEN)}), olc::GREEN),
			b2 = std::make_shared<Bezier>(std::vector<PointPtr>({std::make_shared<Point>(0,0, olc::BLUE),
											 std::make_shared<Point>(0,0, olc::BLUE),
											 std::make_shared<Point>(0,0, olc::BLUE),
											 std::make_shared<Point>(0,0, olc::BLUE)}), olc::BLUE),
			t = std::make_shared<Slider<float>>(0.5, 0, 1, 20, "t"),
		};
	}

	void onK1(float dt) override {
		float alpha = t->value;

		std::array<std::array<olc::vf2d, 4>, 4> beta;

		for (size_t j = 0; j < 4; j++)
			beta[0][j] = b->getHandles()[j]->pos;

		for (size_t j = 1; j < 4; j++)
			for (size_t k = 0; k < 4 - j; k++)
				beta[j][k] = beta[j - 1][k] * (1 - alpha) + beta[j - 1][k + 1] * alpha;


		for (size_t i = 0; i <= 3; i++) {
			b1->getHandles()[i]->pos = beta[i][0];
			b2->getHandles()[i]->pos = beta[i][3-i];			
		}

		return;
	}
};

