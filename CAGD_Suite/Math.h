#pragma once
#include "olcPixelGameEngine.h"
#include <vector>

int factorial(int n);

int binom(int n, int i);

float Bernstein(int n, int i, float t);

olc::vf3d deCasteljau(float t, std::vector<olc::vf3d> handles);
