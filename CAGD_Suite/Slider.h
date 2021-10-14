#pragma once
#include "olcPixelGameEngine.h"

#include "GeometryObject.h"


class Slider : public GeometryObject
{
public:
	float value;
private:
	float min;
	float max;
	olc::vi2d pos;
	int length;
	std::string name;
public:
	Slider(float value, float min, float max, olc::vi2d pos, int length, std::string name, olc::Pixel color) {
		this->value = value;
		this->min = min;
		this->max = max;
		this->pos = pos;
		this->length = length;
		this->name = name;
		this->color = color;
	}

	void drawYourself(olc::PixelGameEngine& screen, Transform& transform) override {
		screen.DrawLine(pos, pos + olc::vi2d(length, 0), color);
		screen.DrawLine(pos + olc::vi2d(0, 2), pos + olc::vi2d(0, -2), color);
		screen.DrawLine(pos + olc::vi2d(length, 2), pos + olc::vi2d(length, -2), color);
		screen.DrawString(pos + olc::vi2d(-11, -4), name, color);
		screen.DrawString(pos + olc::vi2d(-3, 6), std::to_string((int)min), color);
		screen.DrawString(pos + olc::vi2d(length - 3, 6), std::to_string((int)max), color);
		screen.DrawCircle(pos + olc::vi2d((length * (value - min) / (max - min)), 0), 2, color);
	}
	bool getsGrabbed(olc::vi2d mousePos, Transform& transform) override {
		return (pos.x - 2 < mousePos.x && mousePos.x < pos.x + 2 + length &&
			    pos.y - 2 < mousePos.y && mousePos.y < pos.y + 2);
	}
	void updatePosition(olc::vi2d mousePos, Transform& transform) override {
		value = ((mousePos.x - pos.x) / (float)length) * (max-min) + min;
		value = (min < value) ? value : min;
		value = (value < max) ? value : max;
	}
};

typedef std::shared_ptr<Slider> SliderPtr;
