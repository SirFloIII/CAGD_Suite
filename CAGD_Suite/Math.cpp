#include "math.h"

int factorial(int n) {
	int out = 1;
	for (int i = 1; i <= n; i++)
		out *= i;
	return out;
}

int binom(int n, int i) {
	return factorial(n) / factorial(i) / factorial(n - i);
}

float Bernstein(int n, int i, float t) {
	return binom(n, i) * pow(t, i) * pow(1 - t, n - i);
}

olc::vf2d deCasteljau(float t, std::vector<olc::vf2d> handles) {
	if (handles.size() == 1) return handles[0];
	auto A = deCasteljau(t, std::vector<olc::vf2d>(handles.begin(), handles.end() - 1));
	auto B = deCasteljau(t, std::vector<olc::vf2d>(handles.begin() + 1, handles.end()));
	return (1 - t) * A + t * B;
}
