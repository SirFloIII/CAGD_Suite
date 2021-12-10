#pragma once
#include "olcPixelGameEngine.h"
#include "RetroMenu.h"

#include "GeometryObject.h"

#include "ExerciseProblem.h"

#include "Transform.h"

#include <vector>
#include <memory>

class CAGD_Suite : public olc::PixelGameEngine
{
public:
	CAGD_Suite()
	{
		sAppName = "CGAD Suite";
	}

private:
	Transform transform;
	olc::vf2d vStartPan = { 0.0f, 0.0f };
	olc::vf2d vStartTurn = { 0.0f, 0.0f };



	std::vector<GeometryObjPtr> geoObjs;
	GeometryObjPtr currentlyGrabbedObj;

	ExerciseProblem* exercise;


	olc::Sprite* sprGFX = nullptr;
	menumanager mm;
	menuobject mo;

public:
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;

	void UpdateCamera();
	void RenderBackground();

	void CreateMenu();
	void UpdateMenu();

	void openExercise(ExerciseProblem* ex);
	void resetExercise();

};