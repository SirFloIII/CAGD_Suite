#pragma once
#include "olcPixelGameEngine.h"

#include "Transform.h"

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
};

typedef std::shared_ptr<GeometryObject> GeometryObjPtr;
