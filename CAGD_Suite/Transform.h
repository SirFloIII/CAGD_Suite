#pragma once

#include "olcPixelGameEngine.h"


#define SCREENHEIGHT 480

class Transform
{
public:
	olc::vf2d vOffset = { 0.0f, 0.0f };
	float fScale = 40.0f;
	float fGrid = 1.0f;

	float phi = 0;
	float theta = 0;


	// Convert coordinates from World Space --> Screen Space
	void WorldToScreen(const olc::vf3d& v, int& nScreenX, int& nScreenY);
	olc::vi2d WorldToScreen(const olc::vf3d& v);
	float WorldToScreenDistance(const olc::vf3d& v);

	// Convert coordinates from Screen Space --> World Space
	void ScreenToWorld(int nScreenX, int nScreenY, olc::vf2d& v);
	olc::vf3d ScreenToWorld(const olc::vi2d& v);
	olc::vf3d ScreenToWorld(const olc::vi2d& v, float screen_distance);
};

