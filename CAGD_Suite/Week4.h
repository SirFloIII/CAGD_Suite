#pragma once
#include "ExerciseProblem.h"
#include "GeometryCollection.h"


#define ex_4_26
class BSP_4_26 : public ExerciseProblem
{
private:
	BezierPtr b;
	PointPtr A, B, C, D;

public:
	vector<GeometryObjPtr> doSetup() override {
		description = "";

		return {
			b = make_shared<Bezier>(vector<PointPtr>({A = make_shared<Point>(  0.0,  -1.0, "A"),
																B = make_shared<Point>(1.0/3.0,   0.0, "B"),
																C = make_shared<Point>(2.0/3.0, 2.0/3.0, "C"),
																D = make_shared<Point>(  1.0,   2.0, "D")}))
		};
	}

};

#define ex_4_29
class BSP_4_29 : public ExerciseProblem
{
private:
	NURBSPtr b;
public:
	vector<GeometryObjPtr> doSetup() override {
		description = "";

		return {
			b = make_shared<NURBS>(vector<PointPtr>({make_shared<Point>(0,  -1, "A"),
															 make_shared<Point>(3,   0, "B"),
															 make_shared<Point>(4, 2, "C"),
															 make_shared<Point>(4, 3, "D"),
															 make_shared<Point>(6, 2, "E"),
															 make_shared<Point>(7, 3, "F")}),
										 vector<float>({ 0, 0, 0, 0, 1, 2, 3, 3, 3, 3 }),
										 3)
		};
	}

};

#define ex_4_30
class BSP_4_30 : public ExerciseProblem
{
private:
	NURBSPtr b;
public:
	vector<GeometryObjPtr> doSetup() override {
		description = "";

		return {
			b = make_shared<NURBS>(vector<PointPtr>({make_shared<Point>(0,  -1, "A"),
															 make_shared<Point>(3,   0, "B"),
															 make_shared<Point>(4, 2, "C"),
															 make_shared<Point>(4, 3, "D"),
															 make_shared<Point>(6, 2, "E")}),
										 vector<float>({ 0,0,0,0,2,6,6,6,6 }),
										 3)
		};
	}

};


class BSP_4_31 : public ExerciseProblem
{
private:
	SliderFloatPtr t_slider;
	vector<NURBSPtr> b;
public:
	vector<GeometryObjPtr> doSetup() override {
		description = "";
		
		vector<olc::Pixel> colors = { olc::WHITE,
		olc::GREEN,
		olc::BLUE,
		olc::YELLOW };

		int NUM_PTS = 5;
		
		for (size_t j = 0; j < 4; j++) {
			vector<PointPtr> pts1;
			vector<float> knots1;
			size_t upper = (j == 0 ? NUM_PTS : (b[j - 1]->getHandles().size() - 1) * 2);
			for (size_t i = 0; i < upper; i++) {
				pts1.push_back(make_shared<Point>(cos(i), sin(i), colors[j]));
				knots1.push_back(i);
			}
			pts1.push_back(pts1[0]);
			knots1.push_back(upper);
			knots1.push_back(upper + 1);
			b.push_back(make_shared<NURBS>(pts1, knots1, 1));
			if (j != 0) b[j]->color = colors[j];
		}

		return { b[0], b[1], b[2], b[3], t_slider = make_shared<Slider<float>>(0.25, 0, 1, 10, "t") };
	}

	void eachFrame(float dt) override {
		for (size_t j = 1; j < b.size(); j++) {
			auto h = b[j-1]->getHandles();
			auto h1 = b[j]->getHandles();
		
			auto t = t_slider->value;

			for (size_t i = 0; i < h.size() - 1; i++) {
				h1[2 * i]->pos = h[i]->pos * (1-t) + h[i+1]->pos * t;
				h1[2 * i + 1]->pos = h[i]->pos * t + h[i + 1]->pos * (1-t);
			}
		}

	}

};

class BSP_4_32 : public ExerciseProblem
{
};