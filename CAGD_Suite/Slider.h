#pragma once
#include "olcPixelGameEngine.h"

#include "GeometryObject.h"

template <typename T>
class Slider : public GeometryObject
{
public:
	T value;
private:
	T min;
	T max;
	olc::vi2d pos;
	int length = 128;
	std::string name;
public:
	Slider(T value, T min, T max, int line, std::string name) {
		this->value = value;
		this->min = min;
		this->max = max;
		this->pos = {48, 8 * line};
		this->name = name;
		color = olc::WHITE;
	}

	void setMax(T max) {
		this->max = max;
		if (value > max)
			value = max;
	}

	void setMin(T min) {
		this->min = min;
		if (value < min)
			value = min;
	}

	void drawYourself(olc::PixelGameEngine& screen, Transform& transform) override {
		screen.DrawLine(pos + olc::vi2d(8 + 3, 3), pos + olc::vi2d(length + 8 + 3, 3), color);
		screen.DrawLine(pos + olc::vi2d(8 + 3, 0), pos + olc::vi2d(8 + 3, 6), color);
		screen.DrawLine(pos + olc::vi2d(length + 8 + 3, 0), pos + olc::vi2d(length + 8 + 3, 6), color);
		screen.DrawString(pos, name, color);
		screen.DrawString(pos + olc::vi2d(8, 8), std::to_string((int)min), color);
		screen.DrawString(pos + olc::vi2d(length + 8, 8), std::to_string((int)max), color);
		if (max - min)
			screen.DrawCircle(pos + olc::vi2d((length * (value - min) / (max - min)), 0) + olc::vi2d(8 + 3, 3), 2, color);
		else
			screen.DrawCircle(pos + olc::vi2d(length * 0.5, 0), 2, color);
	}
	bool getsGrabbed(olc::vi2d mousePos, Transform& transform) override {
		mousePos -= olc::vi2d(8 + 3, 3);
		return (pos.x - 2 < mousePos.x && mousePos.x < pos.x + 2 + length &&
			    pos.y - 2 < mousePos.y && mousePos.y < pos.y + 2);
	}
	void updatePosition(olc::vi2d mousePos, Transform& transform) override {
		mousePos -= olc::vi2d(8 + 3, 3);
		value = (T)(((mousePos.x - pos.x) / (float)length) * (max-min) + min);
		value = (min <= value) ? value : min;
		value = (value <= max) ? value : max;
	}
};



typedef std::shared_ptr<Slider<float>> SliderFloatPtr;
typedef std::shared_ptr<Slider<int>> SliderIntPtr;
