#pragma once
#include "ExerciseProblem.h"
#include "GeometryCollection.h"



class BSP_1_1 : public ExerciseProblem
{
public:
	std::vector<GeometryObjPtr> doSetup() override {
		PointPtr A = std::make_shared<Point>(1, 0, olc::WHITE);
		PointPtr B = std::make_shared<Point>(1, 1, olc::WHITE);
		PointPtr C = std::make_shared<Point>(0, 1, olc::WHITE);
		PointPtr S = std::make_shared<Point>(0, 0, olc::VERY_DARK_GREY);
		return { std::make_shared<Circle>(S, 1),
				std::make_shared<Bezier>(std::vector<PointPtr>({A, B, C})),
				A, B, C };
	}
};

class BSP_1_2 : public ExerciseProblem
{
private:
	PointPtr A, B, C, D, M;
	SliderPtr x;
	BezierPtr b;
	bool locked = true;

public:
	std::vector<GeometryObjPtr> doSetup() override {
		description = "\
Kreisapproximation:             \n\
                                \n\
  b(1/2; 0, x, 1, 1) =          \n\
                                \n\
  1/8 * ( 1 * 0 +               \n\
          3 * x +               \n\
          3 * 1 +               \n\
          1 * 1 ) =             \n\
                                \n\
  3/8 * x + 4/8                 \n\
                                \n\
      !                         \n\
      =                         \n\
                                \n\
  sqrt2 / 2                     \n\
                                \n\
    ===>                        \n\
                                \n\
  x = 4 * (sqrt2 - 1) / 3       \n\
";


		x = std::make_shared<Slider>(0.6666, 0, 1, olc::vi2d(40, 210), 100, "x", olc::WHITE);

		A = std::make_shared<Point>(1, 0);
		B = std::make_shared<Point>(1, x->value);
		C = std::make_shared<Point>(x->value, 1);
		D = std::make_shared<Point>(0, 1);
		M = std::make_shared<Point>(0, 0, olc::YELLOW);

		return { std::make_shared<Circle>(std::make_shared<Point>(0, 0), 1),
				 b = std::make_shared<Bezier>(std::vector<PointPtr>({A, B, C, D})),
				A, B, C, D, M, x };
	}

	void eachFrame(float dt) override {
		if (locked) {
			A->pos = { 1,0 };
			B->pos = { 1,x->value };
			C->pos = { x->value,1 };
			D->pos = { 0,1 };
		}
		M->pos = b->evaluate(0.5);
	}

	void onSPACE(float dt) override {
		x->value = 4 * (pow(2, 0.5) - 1) / 3;
	}

	void onK1(float dt) override {
		locked = !locked;
	}
};



class BSP_1_5 : public ExerciseProblem
{
public:
	std::vector<GeometryObjPtr> doSetup() override {
		description = "\
Bezierkurve mit singulaerem Punkt: \n\n\
  Wenn die 4 Handles einer     \n\
  3-Bezierkurve in einem       \n\
  verdrehten Parallelogramm    \n\
  liegen, dann hat sie bei     \n\
  t = 1/2 einen singulaeren    \n\
  Punkt.                       \n\n\
    d/dt B3(t, A, B, C, D) =   \n\n\
    3 * B2(t, B-A, C-B, D-C)   \n\n\
                                     \n\
    B2(1/2, B-A, C-B, D-C) =   \n\n\
    1/4 * ((B-A) +    \n\
             2 * (C-B) +  \n\
               (D-C)) =   \n\
                                     \n\
    1/4 * ((C-A) + (D-B)) \
";

		PointPtr A = std::make_shared<Point>(-3, -1, "A");
		PointPtr B = std::make_shared<Point>(3, 1, "B");
		PointPtr C = std::make_shared<Point>(1, -3, "C");
		PointPtr D = std::make_shared<Point>(-1, 3, "D");

		return { std::make_shared<Line>(A, B, olc::DARK_GREY),
				 std::make_shared<Line>(B, C, olc::DARK_GREY),
				 std::make_shared<Line>(C, D, olc::DARK_GREY),
				 std::make_shared<Bezier>(std::vector<PointPtr>({ A, B, C, D })),
				 A, B, C, D };
	}
};


class BSP_1_6 : public ExerciseProblem
{
private:
	PointPtr p0;
	PointPtr p1;
	PointPtr pt;
	SliderPtr t;

	PointPtr A;
	PointPtr B;
	BezierPtr b;
public:
	std::vector<GeometryObjPtr> doSetup() override {
		description = "\
def fitBezier(P0, Pt, P1, t):			\n\
    A = (0, 0)							\n\
    B = bezier(t, P0, A, P1)			\n\
    A = (Pt - B) / bernstein(2, 1, t)	\n\
    return P0, A, P1					\n\
";

		p0 = std::make_shared<Point>(3, -2, "P0");
		p1 = std::make_shared<Point>(4, 3, "P1");
		pt = std::make_shared<Point>(-2, 1, olc::GREEN, "Pt");
		t = std::make_shared<Slider>(0.6, 0, 1, olc::vi2d(40, 128), 100, "t", olc::WHITE);

		A = std::make_shared<Point>(0, 0, "A");
		B = std::make_shared<Point>(0, 0, olc::YELLOW, "B");
		b = std::make_shared<Bezier>(std::vector<PointPtr>({ p0, A, p1 }));

		return { b, p0, p1, pt, A, B, t };
	}
	void eachFrame(float dt) override {
		B->pos = b->evaluate(t->value);
	}

	void onSPACE(float dt) override {
		auto diff = pt->pos - B->pos;
		A->pos += diff / Bernstein(2, 1, t->value);
	}

	void onK1Held(float dt) override {
		auto diff = pt->pos - B->pos;
		A->pos += diff / Bernstein(2, 1, t->value) * dt;
	}
};


class BSP_1_8 : public ExerciseProblem
{
private:
	PointPtr A;
	PointPtr B;
	PointPtr C;
	PointPtr A2;
	PointPtr B2;
	PointPtr C2;
	PointPtr S;
public:
	std::vector<GeometryObjPtr> doSetup() override {
		A = std::make_shared<Point>(1, 5, "A");
		B = std::make_shared<Point>(-2, 1, "B");
		C = std::make_shared<Point>(4, -3, "C");
		A2 = std::make_shared<Point>(0, 0, olc::GREEN, "A'");
		B2 = std::make_shared<Point>(0, 0, olc::GREEN, "B'");
		C2 = std::make_shared<Point>(0, 0, olc::GREEN, "C'");
		S = std::make_shared<Point>(0, 0, olc::RED, "S");
		return { std::make_shared<Line>(A, B, olc::DARK_GREEN),
				 std::make_shared<Line>(B, C, olc::DARK_GREEN),
				 std::make_shared<Line>(C, A, olc::DARK_GREEN),
				 std::make_shared<Line>(A, A2, olc::DARK_RED),
				 std::make_shared<Line>(B, B2, olc::DARK_RED),
				 std::make_shared<Line>(C, C2, olc::DARK_RED),
				 A, B, C, A2, B2, C2, S };
	}
	void eachFrame(float dt) override {
		A2->pos = 0.5 * (B->pos + C->pos);
		B2->pos = 0.5 * (A->pos + C->pos);
		C2->pos = 0.5 * (A->pos + B->pos);
		S->pos = 0.3333333 * (A->pos + B->pos + C->pos);
	}
};
