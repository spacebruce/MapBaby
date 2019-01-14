#pragma once
#include <vector>
#include <array>

#include <SDL.h>
#include <SDL/SDL_opengl.h>

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
	void freeTexture();

	GLuint getTexture() const;
	int getWidth() const;
	int getHeight() const;
	bool isLoaded() const;
};

