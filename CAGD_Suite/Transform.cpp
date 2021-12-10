#include "Transform.h"



void Transform::WorldToScreen(const olc::vf3d& v, int& nScreenX, int& nScreenY)
{
	auto w = WorldToScreen(v);
	nScreenX = w.x;
	nScreenY = w.y;
}

olc::vi2d Transform::WorldToScreen(const olc::vf3d& v)
{
	olc::vf2d w = {             cos(phi) * v.x              - sin(phi) * v.y,
				   sin(phi) * cos(theta) * v.x + cos(phi) * cos(theta) * v.y + sin(theta) * v.z };

	return { (int)((w.x - vOffset.x) * fScale) ,
			 (int)(SCREENHEIGHT - ((w.y - vOffset.y) * fScale)) };
}

float Transform::WorldToScreenDistance(const olc::vf3d& v)
{
	return - sin(phi) * sin(theta) * v.x - cos(phi) * sin(theta) * v.y + cos(theta) * v.z;
}

// Convert coordinates from Screen Space --> World Space

void Transform::ScreenToWorld(int nScreenX, int nScreenY, olc::vf2d& v)
{
	v.x = (float)(nScreenX) / fScale + vOffset.x;
	v.y = (float)(SCREENHEIGHT - nScreenY) / fScale + vOffset.y;
}


olc::vf3d Transform::ScreenToWorld(const olc::vi2d& v) {
	return ScreenToWorld(v, 0);
}

olc::vf3d Transform::ScreenToWorld(const olc::vi2d& v, float screen_distance) {

	olc::vf3d w = { (float)v.x / fScale + vOffset.x,
					(float)(SCREENHEIGHT - v.y) / fScale + vOffset.y,
					screen_distance};

	return { cos(phi) * w.x + sin(phi) * cos(theta) * w.y - sin(phi) * sin(theta) * w.z,
			-sin(phi) * w.x + cos(phi) * cos(theta) * w.y - cos(phi) * sin(theta) * w.z,
							             sin(theta) * w.y +            cos(theta) * w.z };
}