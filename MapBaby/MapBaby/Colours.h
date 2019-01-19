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

struct ColourRGBA
{
	GLubyte r;
	GLubyte g;
	GLubyte b;
	GLubyte a;

	ColourRGBA() = default;
	ColourRGBA(GLubyte r, GLubyte g, GLubyte b, GLubyte a) : r(r), g(g), b(b), a(a) {};
};