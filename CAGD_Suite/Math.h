#pragma once

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



