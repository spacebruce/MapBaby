#pragma once
#include <SDL.h>
#include <SDL/SDL_opengl.h>

class MapEditor
{

public:
	MapEditor();
	~MapEditor();

	void render(const int WindowWidth, const int WindowHeight);
};