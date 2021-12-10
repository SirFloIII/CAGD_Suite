#pragma once
#include "ExerciseProblem.h"
#include "GeometryCollection.h"

class BSP_5_34 : public ExerciseProblem
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


class BSP_5_35 : public ExerciseProblem
{
private:
	NURBSPtr b;
public:
	std::vector<GeometryObjPtr> doSetup() override {
		description = "";

		float s = sqrt(2) / 2;

		return {
			b = std::make_shared<NURBS>(std::vector<PointPtr>({std::make_shared<Point>(2, 0),
															 std::make_shared<Point>(2, 1),
															 std::make_shared<Point>(0, 1),
															 std::make_shared<Point>(-2, 1),
															 std::make_shared<Point>(-2, 0),
															 std::make_shared<Point>(-2, -1),
															 std::make_shared<Point>(0, -1),
															 std::make_shared<Point>(2, -1),
															 std::make_shared<Point>(2, 0),
										}),
										 std::vector<float>({0,0,0,1,1,2,2,3,3,4,4,4}),
										 std::vector<float>({1,s,1,s,1,s,1,s,1}),
										 2)
		};
	}

};
