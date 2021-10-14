#pragma once

#include "GeometryObject.h"

#define interactive_keys \
on(SPACE) \
on(K1) \
on(K2) \
on(K3) \
on(K4) \
on(K5)

class ExerciseProblem
{
public:
	virtual std::vector<GeometryObjPtr> doSetup() { return {}; }
	virtual void eachFrame(float dt) {}
	
#define on(key) \
	virtual void on##key##(float dt) {} \
	virtual void on##key##Held(float dt) {}
	
	interactive_keys
#undef on

	std::string description = "";
};

