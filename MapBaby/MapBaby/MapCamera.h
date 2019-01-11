#pragma once
#include <SDL.h>

#include "MathsHelpers.h"

class MapCamera
{
public:
	int x = 0;
	int y = 0;
	float zoom = 100.0;

	float mouseX = 0.0f;
	float mouseY = 0.0f;

	float left, top, right, bottom;

	void updateOrtho(const int WindowWidth, const int WindowHeight);
	void updateMouse(const int WindowWidth, const int WindowHeight);

	MapCamera();
	~MapCamera();
};