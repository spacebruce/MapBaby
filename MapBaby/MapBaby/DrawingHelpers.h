#pragma once
#include <SDL.h>
#include <SDL/SDL_opengl.h>

namespace Drawing
{
	void DrawLine(float x, float y, float x2, float y2);
	void DrawRectangleOutline(float x, float y, float x2, float y2);
}