#pragma once

#include "CAGD_Suite.h"

#include "Week1.h"


ExerciseProblem* getExerciseByID(int id) {
	switch (id) {
	case(101):
		return new BSP_1_1();
	case(102):
		return new BSP_1_2();
	case(105):
		return new BSP_1_5();
	case(106):
		return new BSP_1_6();
	case(108):
		return new BSP_1_8();
	default:
		return nullptr;
	}
}



void CAGD_Suite::CreateMenu() {
	sprGFX = new olc::Sprite("RetroMenu.png");
	mo["main"].SetTable(1, 15);

	mo["main"]["Reset"].SetID(001);

	mo["main"]["Week  1"].SetTable(1, 9);
	mo["main"]["Week  1"]["Exercise 1"].SetID(101);
	mo["main"]["Week  1"]["Exercise 2"].SetID(102);
	mo["main"]["Week  1"]["Exercise 3"].SetID(103).Enable(false);
	mo["main"]["Week  1"]["Exercise 4"].SetID(104).Enable(false);
	mo["main"]["Week  1"]["Exercise 5"].SetID(105);
	mo["main"]["Week  1"]["Exercise 6"].SetID(106);
	mo["main"]["Week  1"]["Exercise 7"].SetID(107).Enable(false);
	mo["main"]["Week  1"]["Exercise 8"].SetID(108);
	mo["main"]["Week  1"]["Exercise 9"].SetID(109).Enable(false);
	mo["main"]["Week  2"].SetTable(1, 9).Enable(false);
	mo["main"]["Week  2"]["Exercise 1"].SetID(201).Enable(false);
	mo["main"]["Week  2"]["Exercise 2"].SetID(202).Enable(false);
	mo["main"]["Week  2"]["Exercise 3"].SetID(203).Enable(false);
	mo["main"]["Week  2"]["Exercise 4"].SetID(204).Enable(false);
	mo["main"]["Week  2"]["Exercise 5"].SetID(205).Enable(false);
	mo["main"]["Week  2"]["Exercise 6"].SetID(206).Enable(false);
	mo["main"]["Week  2"]["Exercise 7"].SetID(207).Enable(false);
	mo["main"]["Week  2"]["Exercise 8"].SetID(208).Enable(false);
	mo["main"]["Week  2"]["Exercise 9"].SetID(209).Enable(false);
	mo["main"]["Week  3"].SetTable(1, 9).Enable(false);
	mo["main"]["Week  3"]["Exercise 1"].SetID(301).Enable(false);
	mo["main"]["Week  3"]["Exercise 2"].SetID(302).Enable(false);
	mo["main"]["Week  3"]["Exercise 3"].SetID(303).Enable(false);
	mo["main"]["Week  3"]["Exercise 4"].SetID(304).Enable(false);
	mo["main"]["Week  3"]["Exercise 5"].SetID(305).Enable(false);
	mo["main"]["Week  3"]["Exercise 6"].SetID(306).Enable(false);
	mo["main"]["Week  3"]["Exercise 7"].SetID(307).Enable(false);
	mo["main"]["Week  3"]["Exercise 8"].SetID(308).Enable(false);
	mo["main"]["Week  3"]["Exercise 9"].SetID(309).Enable(false);
	mo["main"]["Week  4"].SetTable(1, 9).Enable(false);
	mo["main"]["Week  4"]["Exercise 1"].SetID(401).Enable(false);
	mo["main"]["Week  4"]["Exercise 2"].SetID(402).Enable(false);
	mo["main"]["Week  4"]["Exercise 3"].SetID(403).Enable(false);
	mo["main"]["Week  4"]["Exercise 4"].SetID(404).Enable(false);
	mo["main"]["Week  4"]["Exercise 5"].SetID(405).Enable(false);
	mo["main"]["Week  4"]["Exercise 6"].SetID(406).Enable(false);
	mo["main"]["Week  4"]["Exercise 7"].SetID(407).Enable(false);
	mo["main"]["Week  4"]["Exercise 8"].SetID(408).Enable(false);
	mo["main"]["Week  4"]["Exercise 9"].SetID(409).Enable(false);
	mo["main"]["Week  5"].SetTable(1, 9).Enable(false);
	mo["main"]["Week  5"]["Exercise 1"].SetID(501).Enable(false);
	mo["main"]["Week  5"]["Exercise 2"].SetID(502).Enable(false);
	mo["main"]["Week  5"]["Exercise 3"].SetID(503).Enable(false);
	mo["main"]["Week  5"]["Exercise 4"].SetID(504).Enable(false);
	mo["main"]["Week  5"]["Exercise 5"].SetID(505).Enable(false);
	mo["main"]["Week  5"]["Exercise 6"].SetID(506).Enable(false);
	mo["main"]["Week  5"]["Exercise 7"].SetID(507).Enable(false);
	mo["main"]["Week  5"]["Exercise 8"].SetID(508).Enable(false);
	mo["main"]["Week  5"]["Exercise 9"].SetID(509).Enable(false);
	mo["main"]["Week  6"].SetTable(1, 9).Enable(false);
	mo["main"]["Week  6"]["Exercise 1"].SetID(601).Enable(false);
	mo["main"]["Week  6"]["Exercise 2"].SetID(602).Enable(false);
	mo["main"]["Week  6"]["Exercise 3"].SetID(603).Enable(false);
	mo["main"]["Week  6"]["Exercise 4"].SetID(604).Enable(false);
	mo["main"]["Week  6"]["Exercise 5"].SetID(605).Enable(false);
	mo["main"]["Week  6"]["Exercise 6"].SetID(606).Enable(false);
	mo["main"]["Week  6"]["Exercise 7"].SetID(607).Enable(false);
	mo["main"]["Week  6"]["Exercise 8"].SetID(608).Enable(false);
	mo["main"]["Week  6"]["Exercise 9"].SetID(609).Enable(false);
	mo["main"]["Week  7"].SetTable(1, 9).Enable(false);
	mo["main"]["Week  7"]["Exercise 1"].SetID(701).Enable(false);
	mo["main"]["Week  7"]["Exercise 2"].SetID(702).Enable(false);
	mo["main"]["Week  7"]["Exercise 3"].SetID(703).Enable(false);
	mo["main"]["Week  7"]["Exercise 4"].SetID(704).Enable(false);
	mo["main"]["Week  7"]["Exercise 5"].SetID(705).Enable(false);
	mo["main"]["Week  7"]["Exercise 6"].SetID(706).Enable(false);
	mo["main"]["Week  7"]["Exercise 7"].SetID(707).Enable(false);
	mo["main"]["Week  7"]["Exercise 8"].SetID(708).Enable(false);
	mo["main"]["Week  7"]["Exercise 9"].SetID(709).Enable(false);
	mo["main"]["Week  8"].SetTable(1, 9).Enable(false);
	mo["main"]["Week  8"]["Exercise 1"].SetID(801).Enable(false);
	mo["main"]["Week  8"]["Exercise 2"].SetID(802).Enable(false);
	mo["main"]["Week  8"]["Exercise 3"].SetID(803).Enable(false);
	mo["main"]["Week  8"]["Exercise 4"].SetID(804).Enable(false);
	mo["main"]["Week  8"]["Exercise 5"].SetID(805).Enable(false);
	mo["main"]["Week  8"]["Exercise 6"].SetID(806).Enable(false);
	mo["main"]["Week  8"]["Exercise 7"].SetID(807).Enable(false);
	mo["main"]["Week  8"]["Exercise 8"].SetID(808).Enable(false);
	mo["main"]["Week  8"]["Exercise 9"].SetID(809).Enable(false);
	mo["main"]["Week  9"].SetTable(1, 9).Enable(false);
	mo["main"]["Week  9"]["Exercise 1"].SetID(901).Enable(false);
	mo["main"]["Week  9"]["Exercise 2"].SetID(902).Enable(false);
	mo["main"]["Week  9"]["Exercise 3"].SetID(903).Enable(false);
	mo["main"]["Week  9"]["Exercise 4"].SetID(904).Enable(false);
	mo["main"]["Week  9"]["Exercise 5"].SetID(905).Enable(false);
	mo["main"]["Week  9"]["Exercise 6"].SetID(906).Enable(false);
	mo["main"]["Week  9"]["Exercise 7"].SetID(907).Enable(false);
	mo["main"]["Week  9"]["Exercise 8"].SetID(908).Enable(false);
	mo["main"]["Week  9"]["Exercise 9"].SetID(909).Enable(false);
	mo["main"]["Week 10"].SetTable(1, 9).Enable(false);
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
		if (id == 001) {
			resetExercise();
		}
		else {
			openExercise(getExerciseByID(id));
		}
	}

	mm.Draw(*this, sprGFX, { 30,30 });
}















