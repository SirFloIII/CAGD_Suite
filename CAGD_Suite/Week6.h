#pragma once
#include "ExerciseProblem.h"
#include "GeometryCollection.h"


#define ex_6_40
class BSP_6_40 : public ExerciseProblem
{
private:
	PointPtr A, B, C, D, S;
public:
	std::vector<GeometryObjPtr> doSetup() override {
		description = "\
                  (A - B) * (C - D)   \n\
DV(A, B, C, D) = -------------------  \n\
                  (B - C) * (D - A)   \n\
";

		return { A = std::make_shared<Point>(0, 0, "A"),
				 B = std::make_shared<Point>(1, 0, "B"),
				 C = std::make_shared<Point>(1, 1, "C"),
				 D = std::make_shared<Point>(0, 1, "D"),
				 S = std::make_shared<Point>(0, 0, olc::RED),
		};
	}

	void eachFrame(float dt) override {
		olc::vf3d u, v, w, x;
		u = A->pos - B->pos;
		v = C->pos - D->pos;
		w = B->pos - C->pos;
		x = D->pos - A->pos;
		olc::vf3d n, z;
		n = { u.x * v.x - u.y * v.y, u.x * v.y + u.y * v.x };
		z = { w.x * x.x - w.y * x.y, w.x * x.y + w.y * x.x };
		S->pos = { n.x * z.x + n.y * z.y, - n.x * z.y + n.y * z.x };
		S->pos /= z.mag2();
	}
};



#define ex_6_41
class BSP_6_41 : public ExerciseProblem
{
private:
	PointPtr P, Q, R, p, q, r, X, XX, XXX;
public:
	std::vector<GeometryObjPtr> doSetup() override {
		description = "";

		return { P = std::make_shared<Point>(0, 0, olc::RED, "P"),
				 Q = std::make_shared<Point>(1, 0, olc::RED, "Q"),
				 R = std::make_shared<Point>(1, 1, olc::RED, "R"),
				 p = std::make_shared<Point>(5, 1, olc::GREEN, "p"),
				 q = std::make_shared<Point>(1, 2, olc::GREEN, "q"),
				 r = std::make_shared<Point>(3, 4, olc::GREEN, "r"),
				 X = std::make_shared<Point>(0, 0, olc::WHITE, "X"),
		};
	}

	olc::vf3d DV(PointPtr A, PointPtr B, PointPtr C, PointPtr D) {
		olc::vf3d u, v, w, x;
		u = A->pos - B->pos;
		v = C->pos - D->pos;
		w = B->pos - C->pos;
		x = D->pos - A->pos;
		olc::vf3d n, z, dv;
		n = { u.x * v.x - u.y * v.y, u.x * v.y + u.y * v.x };
		z = { w.x * x.x - w.y * x.y, w.x * x.y + w.y * x.x };
		dv = { n.x * z.x + n.y * z.y, -n.x * z.y + n.y * z.x };
		dv /= z.mag2();
		return dv;
	}

	void eachFrame(float dt) override {
		
	}
};
