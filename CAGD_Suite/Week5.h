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
			b = make_shared<NURBS>(vector<PointPtr>({make_shared<Point>(2, 0),
										             make_shared<Point>(2, 1),
										             make_shared<Point>(0, 1),
										             make_shared<Point>(-2, 1),
										             make_shared<Point>(-2, 0),
										             make_shared<Point>(-2, -1),
										             make_shared<Point>(0, -1),
										             make_shared<Point>(2, -1),
										             make_shared<Point>(2, 0),
										}),
										 vector<float>({0,0,0,1,1,2,2,3,3,4,4,4}),
										 vector<float>({1,s,1,s,1,s,1,s,1}),
										 2)
		};
	}

};

class BSP_5_36 : public ExerciseProblem
{
private:
	BezierSurfacePtr b;
public:
	std::vector<GeometryObjPtr> doSetup() override {
		description = "";

		return {
			b = make_shared<BezierSurface>(vector<PointPtr>({make_shared<Point>(2, 0, 4),
															 make_shared<Point>(3, 1, 2),
															 make_shared<Point>(0, 2, 0),
															 make_shared<Point>(-2, 1, 3)}),
															 2)
		};
	}

};

class BSP_5_37 : public ExerciseProblem
{
private:
	BezierSurfacePtr b;
public:
	std::vector<GeometryObjPtr> doSetup() override {
		description = "";

		return {
			b = make_shared<BezierSurface>(vector<PointPtr>({make_shared<Point>(2, 0, 0),
															 make_shared<Point>(2, -1, 0, olc::GREEN),
															 make_shared<Point>(4, -2, 1),
															 make_shared<Point>(1, 0, 0, olc::RED),
															 make_shared<Point>(2, -2, 2, olc::YELLOW),
															 make_shared<Point>(4, -2, 3, olc::RED),
															 make_shared<Point>(3, -1, 4),
															 make_shared<Point>(4, -2, 4, olc::GREEN),
															 make_shared<Point>(4, -2, 5)}),
															 3)
		};
	}
};


class BSP_5_38 : public ExerciseProblem
{
private:
	NURBSSurfacePtr b;
public:
	std::vector<GeometryObjPtr> doSetup() override {
		description = "";

		float s = sqrt(2) / 2;

		return {
			b = make_shared<NURBSSurface>(vector<PointPtr>({make_shared<Point>(3, 0, 0),
															make_shared<Point>(3, 3, 0),
															make_shared<Point>(0, 3, 0),
															make_shared<Point>(1, 0, 5),
															make_shared<Point>(1, 1, 5),
															make_shared<Point>(0, 1, 5)}),
										3,
										vector<float>({0,0,0,1,1,2,2,2}),
										vector<float>({0,1,2}),
										vector<float>({1, s, 1, 1, s, 1}),
										2,
										1)
		};
	}
};

class BSP_5_39 : public ExerciseProblem
{
private:
	NURBSSurfacePtr b;
public:
	std::vector<GeometryObjPtr> doSetup() override {
		description = "";

		float s = sqrt(2) / 2;

		return {
			b = make_shared<NURBSSurface>(vector<PointPtr>({make_shared<Point>( 0,  0, -1),
															make_shared<Point>( 0,  0, -1),
															make_shared<Point>( 0,  0, -1),
															make_shared<Point>( 0,  0, -1),
															make_shared<Point>( 0,  0, -1),
															make_shared<Point>( 0,  0, -1),
															make_shared<Point>( 0,  0, -1),
															make_shared<Point>( 0,  0, -1),
															make_shared<Point>( 0,  0, -1), //
															make_shared<Point>( 1,  0, -1),
															make_shared<Point>( 1,  1, -1),
															make_shared<Point>( 0,  1, -1),
															make_shared<Point>(-1,  1, -1),
															make_shared<Point>(-1,  0, -1),
															make_shared<Point>(-1, -1, -1),
															make_shared<Point>( 0, -1, -1),
															make_shared<Point>( 1, -1, -1),
															make_shared<Point>( 1,  0, -1), //
															make_shared<Point>( 1,  0,  0),
															make_shared<Point>( 1,  1,  0),
															make_shared<Point>( 0,  1,  0),
															make_shared<Point>(-1,  1,  0),
															make_shared<Point>(-1,  0,  0),
															make_shared<Point>(-1, -1,  0),
															make_shared<Point>( 0, -1,  0),
															make_shared<Point>( 1, -1,  0),
															make_shared<Point>( 1,  0,  0), //
															make_shared<Point>( 1,  0,  1),
															make_shared<Point>( 1,  1,  1),
															make_shared<Point>( 0,  1,  1),
															make_shared<Point>(-1,  1,  1),
															make_shared<Point>(-1,  0,  1),
															make_shared<Point>(-1, -1,  1),
															make_shared<Point>( 0, -1,  1),
															make_shared<Point>( 1, -1,  1),
															make_shared<Point>( 1,  0,  1), //
															make_shared<Point>( 0,  0,  1),
															make_shared<Point>( 0,  0,  1),
															make_shared<Point>( 0,  0,  1),
															make_shared<Point>( 0,  0,  1),
															make_shared<Point>( 0,  0,  1),
															make_shared<Point>( 0,  0,  1),
															make_shared<Point>( 0,  0,  1),
															make_shared<Point>( 0,  0,  1),
															make_shared<Point>( 0,  0,  1), //
										}),
										9,
										vector<float>({0,0,0,1,1,2,2,3,3,4,4,4}),
										vector<float>({0,0,0,1,1,2,2,3,3,4,4,4}),
										vector<float>({1,s,1,s,1,s,1,s,1,
													   1,s,1,s,1,s,1,s,1,
													   1,s,1,s,1,s,1,s,1,
													   1,s,1,s,1,s,1,s,1,
													   1,s,1,s,1,s,1,s,1}),
										2,
										2)
		};
	}
};