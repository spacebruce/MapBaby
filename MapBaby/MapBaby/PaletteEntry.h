#pragma once
#include <cstdint>
#include <SDL/SDL_opengl.h>

struct PaletteEntry
{
	GLubyte r;
	GLubyte g;
	GLubyte b;
	std::uint8_t out;

	PaletteEntry(GLubyte r, GLubyte g, GLubyte b, std::uint8_t out) : r(r), g(g), b(b), out(out) {};
};