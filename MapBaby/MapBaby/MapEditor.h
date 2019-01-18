#pragma once
#include <SDL.h>
#include <SDL/SDL_opengl.h>

#include "TileManager.h"

#include "DrawingHelpers.h"
#include "Map.h"
#include "MapCamera.h"

class MapEditor
{
private:
	TileManager * tileManager;
	Map *map;
public:
	MapCamera camera;

	MapEditor(TileManager& tileManager);

	~MapEditor();

	void update(const int WindowWidth, const int WindowHeight, const bool CheckInput);
	void render(const int WindowWidth, const int WindowHeight);

	void click();

	void changeMap(Map * map);
};