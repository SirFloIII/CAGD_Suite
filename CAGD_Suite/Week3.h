#pragma once
#include "ExerciseProblem.h"
#include "GeometryCollection.h"



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

