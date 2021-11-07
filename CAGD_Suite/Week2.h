#pragma once
#include "ExerciseProblem.h"
#include "GeometryCollection.h"



class BSP_2_15 : public ExerciseProblem
{
private:
	SliderIntPtr n, i;
	BernsteinPolynomPtr f;
public:
	std::vector<GeometryObjPtr> doSetup() override {
		description = "\
def Bernstein(n, i, t):                                                \n\
    return Binom(n, i) * t**i * (1-t)**(n-i)                           \n\
                                                                       \n\
def Binom(n, i):                                                       \n\
    return Factorial(n) / (Factorial(i) * Factorial(n-i))              \n\
                                                                       \n\
def Factorial(k):                                                      \n\
    if k == 0: return 1                                                \n\
    return k * Factorial(k-1)                                          \n\
";
		
		return { f = std::make_shared<BernsteinPolynom>(0, 0, olc::RED),
				 n = std::make_shared<Slider<int>>(3, 0, 12, 16, "n"),
				 i = std::make_shared<Slider<int>>(2, 0, 10, 20, "i")
		};
	}

	void eachFrame(float dt) {
		i->setMax(n->value);
		f->n = n->value;
		f->i = i->value;
	}
};



class BSP_2_16 : public ExerciseProblem
{
private:
	BezierPtr curve;
	SliderFloatPtr t;
	PointPtr x;

public:
	std::vector<GeometryObjPtr> doSetup() override {
		description = "\
def Bezier(t, handles):                                                \n\
    n = len(handles) - 1                                               \n\
    return sum(Bernstein(n, i, t) * p for i, p in enumerate(handles))  \n\
                                                                       \n\
def Bernstein(n, i, t):                                                \n\
    return Binom(n, i) * t**i * (n-t)**(n-i)                           \n\
                                                                       \n\
def Binom(n, i):                                                       \n\
    return Factorial(n) / (Factorial(i) * Factorial(n-i))              \n\
                                                                       \n\
def Factorial(k):                                                      \n\
    if k == 0: return 1                                                \n\
    return k * Factorial(k-1)                                          \n\
";

		std::vector<GeometryObjPtr> out;
		std::vector<PointPtr> points;
		for (int i = 0; i < 5; i++) {
			points.push_back(std::make_shared<Point>(i, i * i / 8));
			out.push_back(points[i]);
		}
		out.push_back(curve = std::make_shared<Bezier>(points));
		out.push_back(x = std::make_shared<Point>(0, 0, olc::YELLOW));
		out.push_back(t = std::make_shared<Slider<float>>(0.5, 0, 1, 20, "t"));
		return out;
	}

	void eachFrame(float dt) override {
		x->pos = curve->evaluate(t->value);
	}

};

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