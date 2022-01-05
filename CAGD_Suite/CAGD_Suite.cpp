#include "CAGD_Suite.h"

ExerciseProblem* CAGD_Suite::getExerciseByID(int id) {
	switch (id) {
	case(1):
		return new BSP_1_1();
	case(2):
		return new BSP_1_2();
	case(3):
		return new BSP_1_3();
	case(4):
		return new BSP_1_4();
	case(5):
		return new BSP_1_5();
	case(6):
		return new BSP_1_6();
	case(7):
		return new BSP_1_7();
	case(8):
		return new BSP_1_8();
	case(15):
		return new BSP_2_15();
	case(16):
		return new BSP_2_16();
	case(17):
		return new BSP_2_17();
	case(18):
		return new BSP_3_18();
	case(21):
		return new BSP_3_21();
	case(26):
		return new BSP_4_26();
	case(29):
		return new BSP_4_29();
	case(30):
		return new BSP_4_30();
	case(31):
		return new BSP_4_31();
	case(32):
		return new BSP_4_32();
	case(34):
		return new BSP_5_34();
	case(35):
		return new BSP_5_35();
	case(36):
		return new BSP_5_36();
	case(37):
		return new BSP_5_37();
	case(38):
		return new BSP_5_38();
	case(39):
		return new BSP_5_39();
	default:
		return nullptr;
	}
}


void CAGD_Suite::CreateMenu() {
	sprGFX = new olc::Sprite("./assets/RetroMenu.png");
	mo["main"].SetTable(1, 15);

	mo["main"]["Reset"].SetID(999);

	mo["main"]["Week  1"].SetTable(1, 10);
	mo["main"]["Week  2"].SetTable(1, 10);
	mo["main"]["Week  3"].SetTable(1, 10);
	mo["main"]["Week  4"].SetTable(1, 10);
	mo["main"]["Week  5"].SetTable(1, 10);
	mo["main"]["Week  6"].SetTable(1, 10).Enable(false);
	mo["main"]["Week  7"].SetTable(1, 10).Enable(false);
	mo["main"]["Week  8"].SetTable(1, 10).Enable(false);
	mo["main"]["Week  9"].SetTable(1, 10).Enable(false);
	mo["main"]["Week 10"].SetTable(1, 10).Enable(false);
	mo["main"]["Week  1"]["Exercise 1"].SetID(1);
	mo["main"]["Week  1"]["Exercise 2"].SetID(2);
	mo["main"]["Week  1"]["Exercise 3"].SetID(3);
	mo["main"]["Week  1"]["Exercise 4"].SetID(4);
	mo["main"]["Week  1"]["Exercise 5"].SetID(5);
	mo["main"]["Week  1"]["Exercise 6"].SetID(6);
	mo["main"]["Week  1"]["Exercise 7"].SetID(7);
	mo["main"]["Week  1"]["Exercise 8"].SetID(8);
	mo["main"]["Week  1"]["Exercise 9"].SetID(9).Enable(false);
	mo["main"]["Week  2"]["Exercise 10"].SetID(10).Enable(false);
	mo["main"]["Week  2"]["Exercise 11"].SetID(11).Enable(false);
	mo["main"]["Week  2"]["Exercise 12"].SetID(12).Enable(false);
	mo["main"]["Week  2"]["Exercise 13"].SetID(13).Enable(false);
	mo["main"]["Week  2"]["Exercise 14"].SetID(14).Enable(false);
	mo["main"]["Week  2"]["Exercise 15"].SetID(15);
	mo["main"]["Week  2"]["Exercise 16"].SetID(16);
	mo["main"]["Week  2"]["Exercise 17"].SetID(17);
	mo["main"]["Week  3"]["Exercise 18"].SetID(18);
	mo["main"]["Week  3"]["Exercise 19"].SetID(19).Enable(false);
	mo["main"]["Week  3"]["Exercise 20"].SetID(20).Enable(false);
	mo["main"]["Week  3"]["Exercise 21"].SetID(21);
	mo["main"]["Week  3"]["Exercise 22"].SetID(22).Enable(false);
	mo["main"]["Week  3"]["Exercise 23"].SetID(23).Enable(false);
	mo["main"]["Week  4"]["Exercise 24"].SetID(24).Enable(false);
	mo["main"]["Week  4"]["Exercise 25"].SetID(25).Enable(false);
	mo["main"]["Week  4"]["Exercise 26"].SetID(26);
	mo["main"]["Week  4"]["Exercise 27"].SetID(27).Enable(false);
	mo["main"]["Week  4"]["Exercise 28"].SetID(28).Enable(false);
	mo["main"]["Week  4"]["Exercise 29"].SetID(29);
	mo["main"]["Week  4"]["Exercise 30"].SetID(30);
	mo["main"]["Week  4"]["Exercise 31"].SetID(31);
	mo["main"]["Week  4"]["Exercise 32"].SetID(32);
	mo["main"]["Week  4"]["Exercise 33"].SetID(33).Enable(false);
	mo["main"]["Week  5"]["Exercise 34"].SetID(34);
	mo["main"]["Week  5"]["Exercise 35"].SetID(35);
	mo["main"]["Week  5"]["Exercise 36"].SetID(36);
	mo["main"]["Week  5"]["Exercise 37"].SetID(37);
	mo["main"]["Week  5"]["Exercise 38"].SetID(38);
	mo["main"]["Week  5"]["Exercise 39"].SetID(39);
	mo["main"]["Week  6"]["Exercise 1"].SetID(601).Enable(false);
	mo["main"]["Week  6"]["Exercise 2"].SetID(602).Enable(false);
	mo["main"]["Week  6"]["Exercise 3"].SetID(603).Enable(false);
	mo["main"]["Week  6"]["Exercise 4"].SetID(604).Enable(false);
	mo["main"]["Week  6"]["Exercise 5"].SetID(605).Enable(false);
	mo["main"]["Week  6"]["Exercise 6"].SetID(606).Enable(false);
	mo["main"]["Week  6"]["Exercise 7"].SetID(607).Enable(false);
	mo["main"]["Week  6"]["Exercise 8"].SetID(608).Enable(false);
	mo["main"]["Week  6"]["Exercise 9"].SetID(609).Enable(false);
	mo["main"]["Week  7"]["Exercise 1"].SetID(701).Enable(false);
	mo["main"]["Week  7"]["Exercise 2"].SetID(702).Enable(false);
	mo["main"]["Week  7"]["Exercise 3"].SetID(703).Enable(false);
	mo["main"]["Week  7"]["Exercise 4"].SetID(704).Enable(false);
	mo["main"]["Week  7"]["Exercise 5"].SetID(705).Enable(false);
	mo["main"]["Week  7"]["Exercise 6"].SetID(706).Enable(false);
	mo["main"]["Week  7"]["Exercise 7"].SetID(707).Enable(false);
	mo["main"]["Week  7"]["Exercise 8"].SetID(708).Enable(false);
	mo["main"]["Week  7"]["Exercise 9"].SetID(709).Enable(false);
	mo["main"]["Week  8"]["Exercise 1"].SetID(801).Enable(false);
	mo["main"]["Week  8"]["Exercise 2"].SetID(802).Enable(false);
	mo["main"]["Week  8"]["Exercise 3"].SetID(803).Enable(false);
	mo["main"]["Week  8"]["Exercise 4"].SetID(804).Enable(false);
	mo["main"]["Week  8"]["Exercise 5"].SetID(805).Enable(false);
	mo["main"]["Week  8"]["Exercise 6"].SetID(806).Enable(false);
	mo["main"]["Week  8"]["Exercise 7"].SetID(807).Enable(false);
	mo["main"]["Week  8"]["Exercise 8"].SetID(808).Enable(false);
	mo["main"]["Week  8"]["Exercise 9"].SetID(809).Enable(false);
	mo["main"]["Week  9"]["Exercise 1"].SetID(901).Enable(false);
	mo["main"]["Week  9"]["Exercise 2"].SetID(902).Enable(false);
	mo["main"]["Week  9"]["Exercise 3"].SetID(903).Enable(false);
	mo["main"]["Week  9"]["Exercise 4"].SetID(904).Enable(false);
	mo["main"]["Week  9"]["Exercise 5"].SetID(905).Enable(false);
	mo["main"]["Week  9"]["Exercise 6"].SetID(906).Enable(false);
	mo["main"]["Week  9"]["Exercise 7"].SetID(907).Enable(false);
	mo["main"]["Week  9"]["Exercise 8"].SetID(908).Enable(false);
	mo["main"]["Week  9"]["Exercise 9"].SetID(909).Enable(false);
	mo["main"]["Week 10"]["Exercise 1"].SetID(1001).Enable(false);
	mo["main"]["Week 10"]["Exercise 2"].SetID(1002).Enable(false);
	mo["main"]["Week 10"]["Exercise 3"].SetID(1003).Enable(false);
	mo["main"]["Week 10"]["Exercise 4"].SetID(1004).Enable(false);
	mo["main"]["Week 10"]["Exercise 5"].SetID(1005).Enable(false);
	mo["main"]["Week 10"]["Exercise 6"].SetID(1006).Enable(false);
	mo["main"]["Week 10"]["Exercise 7"].SetID(1007).Enable(false);
	mo["main"]["Week 10"]["Exercise 8"].SetID(1008).Enable(false);
	mo["main"]["Week 10"]["Exercise 9"].SetID(1009).Enable(false);

	mo.Build();

}



void CAGD_Suite::UpdateMenu() {
	menuobject* command = nullptr;

	if (GetKey(olc::Key::CTRL).bPressed)   mm.Open(&mo["main"]);

	if (GetKey(olc::Key::UP).bPressed)		mm.OnUp();
	if (GetKey(olc::Key::DOWN).bPressed)	mm.OnDown();
	if (GetKey(olc::Key::LEFT).bPressed)	mm.OnLeft();
	if (GetKey(olc::Key::RIGHT).bPressed)	mm.OnRight();
	if (GetKey(olc::Key::ENTER).bPressed)	command = mm.OnConfirm();
	if (GetKey(olc::Key::BACK).bPressed)  mm.OnBack();

	if (command != nullptr)
	{
		mm.Close();
		auto id = command->GetID();
		if (id == 999) {
			resetExercise();
		}
		else {
			openExercise(getExerciseByID(id));
		}
	}

	mm.Draw(*this, sprGFX, { 30,30 });
}

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
		if (GetKey(olc::key).bPressed) exercise->on##key(dt); \
		if (GetKey(olc::key).bHeld) exercise->on##key##Held(dt);
		interactive_keys
#undef on
	}

	if (GetMouse(0).bPressed) {
		for (auto obj : geoObjs) {
			if (obj->getsGrabbed(GetMousePos(), transform))
			{
				currentlyGrabbedObj = obj;
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
	
	// Handle Pan & Zoom
	if (GetMouse(2).bPressed)
	{
		vStartTurn = mouseOnScreen;
	}

	if (GetMouse(2).bHeld)
	{
		transform.phi += (mouseOnScreen.x - vStartTurn.x)/100;
		transform.theta += (mouseOnScreen.y - vStartTurn.y)/100;
		vStartTurn = mouseOnScreen;
	}


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

float max(float x, float y)
{
	return x > y ? x : y;
}

float min(float x, float y)
{
	return x < y ? x : y;
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
	vWorldTopLeft.x = min(vWorldTopLeft.x, vWorldTopLeft.y);
	vWorldTopLeft.y = min(vWorldTopLeft.x, vWorldTopLeft.y);

	vWorldBottomRight.x = max(vWorldBottomRight.x, vWorldBottomRight.y);
	vWorldBottomRight.y = max(vWorldBottomRight.x, vWorldBottomRight.y);

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
		for (auto obj : objs) {
			geoObjs.push_back(obj);
			for (auto o : obj->getExports())
				if (std::count(geoObjs.begin(), geoObjs.end(), o) == 0) geoObjs.push_back(o);
		}
	}
}

void CAGD_Suite::resetExercise()
{
	delete exercise;
	exercise = nullptr;
	geoObjs.erase(geoObjs.begin(), geoObjs.end());
}

