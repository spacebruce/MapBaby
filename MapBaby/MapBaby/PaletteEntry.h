#pragma once
#include <cstdint>
#include <SDL/SDL_opengl.h>

struct PaletteEntry
{
	GLubyte r;
	GLubyte g;
	GLubyte b;

	PaletteEntry() = default;
	PaletteEntry(GLubyte r, GLubyte g, GLubyte b) : r(r), g(g), b(b) {};
};