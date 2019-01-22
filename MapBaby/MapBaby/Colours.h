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
	ColourRGB(float r, float g, float b)
	{
		this->r = static_cast<GLubyte>(r);
		this->g = static_cast<GLubyte>(g);
		this->b = static_cast<GLubyte>(b);
	};
	ColourRGB(int r, int g, int b)
	{
		this->r = static_cast<GLubyte>(r);
		this->g = static_cast<GLubyte>(g);
		this->b = static_cast<GLubyte>(b);
	};

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
	ColourRGBA(float r, float g, float b, float a)
	{
		this->r = static_cast<GLubyte>(r);
		this->g = static_cast<GLubyte>(g);
		this->b = static_cast<GLubyte>(b);
		this->a = static_cast<GLubyte>(a);
	};
	ColourRGBA(int r, int g, int b, int a)
	{
		this->r = static_cast<GLubyte>(r);
		this->g = static_cast<GLubyte>(g);
		this->b = static_cast<GLubyte>(b);
		this->a = static_cast<GLubyte>(a);
	};

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