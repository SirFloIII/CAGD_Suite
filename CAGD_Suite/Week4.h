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
	std::vector<GeometryObjPtr> doSetup() override {
		description = "";

		return {
			b = std::make_shared<Bezier>(std::vector<PointPtr>({A = std::make_shared<Point>(  0.0,  -1.0, "A"),
																B = std::make_shared<Point>(1.0/3.0,   0.0, "B"),
																C = std::make_shared<Point>(2.0/3.0, 2.0/3.0, "C"),
																D = std::make_shared<Point>(  1.0,   2.0, "D")}))
		};
	}

};
