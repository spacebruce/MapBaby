#pragma once
#include <SDL.h>
#include <SDL/SDL_opengl.h>

#include "DrawingHelpers.h"
#include "Map.h"
#include "MapCamera.h"

class MapEditor
{
private:
	Map *map;
public:
	MapCamera camera;

	MapEditor();
	MapEditor(Map * map);

	~MapEditor();

	void render(const int WindowWidth, const int WindowHeight);
	void changeMap(Map * map);
};