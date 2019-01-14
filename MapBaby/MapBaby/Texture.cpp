#include "Texture.h"

Texture::Texture()
{
}

Texture::~Texture()
{
	freeTexture();
}

void Texture::freeTexture()
{
	if (this->isLoaded())
	{
		glDeleteTextures(1, &this->TextureID);
		this->TextureID = 0;
	}
	this->Width = 0;
	this->Height = 0;
}

void Texture::createFromArray(GLuint Width, GLuint Height, GLuint *pixels)
{
	this->freeTexture();

	this->Width = Width;
	this->Height = Height;

	glGenTextures(1, &this->TextureID);
	glBindTexture( GL_TEXTURE_2D, this->TextureID);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Width, Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, NULL);
}

GLuint Texture::getTexture() const
{
	return this->TextureID;
}

int Texture::getWidth() const
{
	return this->Width;
}

int Texture::getHeight() const
{
	return this->Height;
}

bool Texture::isLoaded() const
{
	return (this->TextureID != 0);
}
