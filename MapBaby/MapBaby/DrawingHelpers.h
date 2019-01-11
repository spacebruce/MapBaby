#pragma once
#include <cmath>
#include <SDL.h>
#include <SDL/SDL_opengl.h>

namespace Drawing
{
	const double pi = 3.14159265358979323846264338327950288;
	const double tau = (pi * 2.0);

	void drawLine(const float x, const float y, const float x2, const float y2);
	void drawRectangleOutline(const float x, const float y, const float x2, const float y2);
	void drawCircleOutline(const float x, const float y, const float radius, const int resolution);
}