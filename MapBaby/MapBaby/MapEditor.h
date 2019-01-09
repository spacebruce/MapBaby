#pragma once
#include <SDL.h>
#include <SDL/SDL_opengl.h>

#include "Map.h"

class MapEditor
{
private:
	Map *map;
public:
	MapEditor();
	~MapEditor();

	void render(const int WindowWidth, const int WindowHeight);
};