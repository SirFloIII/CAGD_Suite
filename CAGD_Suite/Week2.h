#pragma once
#include "ExerciseProblem.h"
#include "GeometryCollection.h"

class BSP_2_17 : public ExerciseProblem
{
private:
	CasteljauPtr curve;
	SliderFloatPtr t;
	PointPtr x;

public:
	std::vector<GeometryObjPtr> doSetup() override {
		description = "\
def deCasteljau(t, handles):          \n\
    if len(handles) == 1:             \n\
        return handles[0]             \n\
    A = deCasteljau(t, handles[:-1])  \n\
    B = deCasteljau(t, handles[1:])   \n\
    return (1-t) * A + t * B          \n\
";

		std::vector<GeometryObjPtr> out;
		std::vector<PointPtr> points;
		for (int i = 0; i < 5; i++) {
			points.push_back(std::make_shared<Point>(i, i * i / 8));
			out.push_back(points[i]);
		}
		out.push_back(curve = std::make_shared<Casteljau>(points));
		out.push_back(x = std::make_shared<Point>(0, 0, olc::YELLOW));
		out.push_back(t = std::make_shared<Slider<float>>(0.5, 0, 1, 14, "t"));
		return out;
	}

	void eachFrame(float dt) override {
		curve->t = t->value;
		x->pos = curve->evaluate(t->value);
	}

};