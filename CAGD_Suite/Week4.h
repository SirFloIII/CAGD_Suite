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

#define ex_4_29
class BSP_4_29 : public ExerciseProblem
{
private:
	NURBSPtr b;
public:
	std::vector<GeometryObjPtr> doSetup() override {
		description = "";

		return {
			b = std::make_shared<NURBS>(std::vector<PointPtr>({std::make_shared<Point>(0,  -1, "A"),
															 std::make_shared<Point>(3,   0, "B"),
															 std::make_shared<Point>(4, 2, "C"),
															 std::make_shared<Point>(4, 3, "D"),
															 std::make_shared<Point>(6, 2, "E"),
															 std::make_shared<Point>(7, 3, "F")}),
										 std::vector<float>({ 0, 0, 0, 0, 1, 2, 3, 3, 3, 3 }),
										 3)
		};
	}

};


class Circle_from_NURBS : public ExerciseProblem
{
private:
	NURBSPtr b;
public:
	std::vector<GeometryObjPtr> doSetup() override {
		description = "";

		float s = sqrt(2) / 2;

		return {
			b = std::make_shared<NURBS>(std::vector<PointPtr>({std::make_shared<Point>(1, 0),
															 std::make_shared<Point>(1, 1),
															 std::make_shared<Point>(0, 1),
															 std::make_shared<Point>(-1, 1),
															 std::make_shared<Point>(-1, 0),
															 std::make_shared<Point>(-1, -1),
															 std::make_shared<Point>(0, -1),
															 std::make_shared<Point>(1, -1),
															 std::make_shared<Point>(1, 0),
										}),
										 std::vector<float>({0,0,0,1,1,2,2,3,3,4,4,4}),
										 std::vector<float>({1,s,1,s,1,s,1,s,1}),
										 2)
		};
	}

};
