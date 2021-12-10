#pragma once
#include "olcPixelGameEngine.h"

#include "Transform.h"

using namespace std;

class GeometryObject;

typedef shared_ptr<GeometryObject> GeometryObjPtr;

class GeometryObject
{
public:
	void updateSelf(float dt) {}
	virtual void drawYourself(olc::PixelGameEngine &screen, Transform &transform) {};
	virtual bool getsGrabbed(olc::vi2d mousePos, Transform& transform){
			return false;
	}
	virtual void updatePosition(olc::vi2d mousePos, Transform& transform) {}
	olc::Pixel color;
	virtual vector<GeometryObjPtr> getExports() { return {}; }
};

