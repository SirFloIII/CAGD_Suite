#include "Transform.h"



void Transform::WorldToScreen(const olc::vf2d& v, int& nScreenX, int& nScreenY)
{
	nScreenX = (int)((v.x - vOffset.x) * fScale);
	nScreenY = (int)(SCREENHEIGHT - ((v.y - vOffset.y) * fScale));
}

olc::vi2d Transform::WorldToScreen(const olc::vf2d& v)
{
	return { (int)((v.x - vOffset.x) * fScale) ,
			 (int)(SCREENHEIGHT - ((v.y - vOffset.y) * fScale)) };
}

// Convert coordinates from Screen Space --> World Space

void Transform::ScreenToWorld(int nScreenX, int nScreenY, olc::vf2d& v)
{
	v.x = (float)(nScreenX) / fScale + vOffset.x;
	v.y = (float)(SCREENHEIGHT - nScreenY) / fScale + vOffset.y;
}


olc::vf2d Transform::ScreenToWorld(const olc::vi2d& v) {

	return { (float)v.x / fScale + vOffset.x,
			 (float)(SCREENHEIGHT - v.y) / fScale + vOffset.y };
}