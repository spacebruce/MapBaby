#pragma once
#include <cstdint>
#include <SDL/SDL_opengl.h>

struct ColourRGB
{
	GLubyte r;
	GLubyte g;
	GLubyte b;

	ColourRGB() = default;
	ColourRGB(GLubyte r, GLubyte g, GLubyte b) : r(r), g(g), b(b) {};
};