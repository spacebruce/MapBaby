#pragma once
#include <vector>
#include <array>

#include <SDL.h>
#include <SDL/SDL_opengl.h>

#include "Bitmap.h"
#include "Palette.h"
#include "Colours.h"

class Texture
{
private:
	GLuint TextureID = 0;
	int Width = 0;
	int Height = 0;
public:
	Texture();
	~Texture();

	void createFromArray(GLuint Width, GLuint Height, GLuint * pixels);
	void createFromBitmap(Bitmap& bitmap, Palette& palette);

	void freeTexture();

	GLuint get() const;
	int getWidth() const;
	int getHeight() const;
	bool isLoaded() const;

	void bind();

	//don't actually use this
	void testRender(float x, float y);
};

