#include "CAGD_Suite.h"


bool CAGD_Suite::OnUserCreate()
{
	// Configure world space (0,0) to be middle of screen space
	transform.vOffset = { (float)(-ScreenWidth() / 2) / transform.fScale, (float)(-ScreenHeight() / 2) / transform.fScale };

	CreateMenu();

	return true;
}

bool CAGD_Suite::OnUserUpdate(float dt)
{
	if (exercise) {
		exercise->eachFrame(dt);
#define on(key) \
		if (GetKey(olc::##key##).bPressed) exercise->on##key##(dt); \
		if (GetKey(olc::##key##).bHeld) exercise->on##key##Held(dt);
		interactive_keys
#undef on
	}

	if (GetMouse(0).bPressed) {
		for (auto obj : geoObjs) {
			if (obj->getsGrabbed(GetMousePos(), transform))
			{
				currentlyGrabbedObj = obj;
				break;
			}
		}
	}

	if (GetKey(olc::ESCAPE).bPressed)
		return false;

	if (GetMouse(0).bHeld && currentlyGrabbedObj) {
		currentlyGrabbedObj->updatePosition(GetMousePos(), transform);
	}

	if (GetMouse(0).bReleased) {
		currentlyGrabbedObj = nullptr;
	}


	UpdateCamera();
	RenderBackground();

	for (auto obj : geoObjs) {
		obj->drawYourself(*this, transform);
	}

	if (exercise)
		DrawString({ 32,32 }, exercise->description);

	UpdateMenu();

	return true;
}

void CAGD_Suite::UpdateCamera()
{
	// Get mouse location this frame
	olc::vf2d mouseOnScreen = { (float)GetMouseX(), (float)GetMouseY() };

	// Handle Pan & Zoom
	if (GetMouse(1).bPressed)
	{
		vStartPan = mouseOnScreen;
	}

	if (GetMouse(1).bHeld)
	{
		transform.vOffset.x -= (mouseOnScreen.x - vStartPan.x) / transform.fScale;
		transform.vOffset.y += (mouseOnScreen.y - vStartPan.y) / transform.fScale;
		vStartPan = mouseOnScreen;
	}

	olc::vf2d vMouseBeforeZoom;
	transform.ScreenToWorld((int)mouseOnScreen.x, (int)mouseOnScreen.y, vMouseBeforeZoom);

	if (GetMouseWheel() > 0)
	{
		transform.fScale *= 1.1f;
	}

	if (GetMouseWheel() < 0)
	{
		transform.fScale /= 1.1f;
	}

	olc::vf2d vMouseAfterZoom;
	transform.ScreenToWorld((int)mouseOnScreen.x, (int)mouseOnScreen.y, vMouseAfterZoom);
	transform.vOffset += (vMouseBeforeZoom - vMouseAfterZoom);
}

void CAGD_Suite::RenderBackground()
{
	// Clear Screen
	Clear(olc::VERY_DARK_BLUE);

	int sx, sy;
	int ex, ey;

	// Get visible world
	olc::vf2d vWorldTopLeft, vWorldBottomRight;
	transform.ScreenToWorld(0, ScreenHeight(), vWorldTopLeft);
	transform.ScreenToWorld(ScreenWidth(), 0, vWorldBottomRight);

	// Get values just beyond screen boundaries
	vWorldTopLeft.x = floor(vWorldTopLeft.x);
	vWorldTopLeft.y = floor(vWorldTopLeft.y);
	vWorldBottomRight.x = ceil(vWorldBottomRight.x);
	vWorldBottomRight.y = ceil(vWorldBottomRight.y);

	// Draw Grid dots
	for (float x = vWorldTopLeft.x; x < vWorldBottomRight.x; x += transform.fGrid)
	{
		for (float y = vWorldTopLeft.y; y < vWorldBottomRight.y; y += transform.fGrid)
		{
			transform.WorldToScreen({ x, y }, sx, sy);
			Draw(sx, sy, olc::BLUE);
		}
	}

	// Draw World Axis
	transform.WorldToScreen({ 0,vWorldTopLeft.y }, sx, sy);
	transform.WorldToScreen({ 0,vWorldBottomRight.y }, ex, ey);
	DrawLine(sx, sy, ex, ey, olc::GREY);
	transform.WorldToScreen({ vWorldTopLeft.x,0 }, sx, sy);
	transform.WorldToScreen({ vWorldBottomRight.x,0 }, ex, ey);
	DrawLine(sx, sy, ex, ey, olc::GREY);
}

void CAGD_Suite::openExercise(ExerciseProblem* ex)
{
	resetExercise();
	if (ex) {
		exercise = ex;
		auto objs = exercise->doSetup();
		for (auto obj : objs)
			geoObjs.push_back(obj);
	}
}

void CAGD_Suite::resetExercise()
{
	delete exercise;
	exercise = nullptr;
	geoObjs.erase(geoObjs.begin(), geoObjs.end());
}

