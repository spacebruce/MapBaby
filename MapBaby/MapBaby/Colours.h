#pragma once
#include <cstdint>
#include <cmath>
#include <SDL/SDL_opengl.h>

struct ColourRGB
{
	GLubyte r;
	GLubyte g;
	GLubyte b;

	ColourRGB() = default;
	ColourRGB(GLubyte r, GLubyte g, GLubyte b) : r(r), g(g), b(b) {};

	explicit operator GLuint() const
	{
		return static_cast<GLuint>((0xFF << 24) | (b << 16) | (g << 8) | (r << 0));
	}
};

struct ColourRGBA
{
	GLubyte r;
	GLubyte g;
	GLubyte b;
	GLubyte a;

	ColourRGBA() = default;
	ColourRGBA(GLubyte r, GLubyte g, GLubyte b, GLubyte a) : r(r), g(g), b(b), a(a) {};

	explicit operator GLuint() const
	{
		return static_cast<GLuint>((a << 24) | (b << 16) | (g << 8) | (r << 0));
	}
};

inline float distance(const ColourRGB left, const ColourRGB right)
{
	return sqrtf((left.r - right.r) ^ 2 + (left.g - right.g) ^ 2 + (left.b - right.b) ^ 2);
}

inline float distance(const ColourRGBA left, const ColourRGBA right)
{
	return sqrtf((left.r - right.r) ^ 2 + (left.g - right.g) ^ 2 + (left.b - right.b) ^ 2 + (left.a - right.a) ^ 2);
}