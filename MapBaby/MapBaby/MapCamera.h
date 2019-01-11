#pragma once
#include <SDL.h>
#include "MathsHelpers.h"

#include "Map.h"

class MapCamera
{
private:
	float mouseX = 0.0f;
	float mouseY = 0.0f;

	int mouseTileX = 0;
	int mouseTileY = 0;
	bool mouseTileValid = false;

	float left, top, right, bottom;

	void updateOrtho(const int WindowWidth, const int WindowHeight);
	void updateMouse(const int WindowWidth, const int WindowHeight, const Map *map);
public:
	int x = 0;
	int y = 0;
	float zoom = 100.0;

	float getMouseX() const;
	float getMouseY() const;

	Numbers::Rectangle<float> getBox();

	int getMouseTileX() const;
	int getMouseTileY() const;
	bool isMouseTileValid() const;

	void update(const int WindowWidth, const int WindowHeight, const Map *map);

	MapCamera();
	~MapCamera();
};