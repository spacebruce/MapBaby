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

	float border[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, border);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Width, Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

	glBindTexture(GL_TEXTURE_2D, NULL);
}

void Texture::createFromBitmap(GLuint Width, GLuint Height, std::uint8_t * bitmap, Palette * palette)
{
	const std::size_t length = (Width * Height);
	GLuint * pixels = new GLuint[length];

	for (std::size_t i = 0; i < length; ++i)
	{
		PaletteEntry colour = palette->getEntry(bitmap[i]);

		GLubyte* pixel = (GLubyte*)&pixels[i];
		pixel[0] = colour.r;
		pixel[1] = colour.g;
		pixel[2] = colour.b;
		pixel[3] = 0xff;
	}

	this->createFromArray(Width, Height, pixels);

	delete pixels;
}

GLuint Texture::get() const
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

void Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, (this->TextureID));
}

void Texture::testRender(int x, int y)
{
	if (!this->isLoaded())
		return;
	//Remove any previous transformations
	glLoadIdentity();

	//Move to rendering point
	glTranslatef(x, y, 0.f);

	glEnable(GL_TEXTURE_2D);
	//Set texture ID
	glBindTexture(GL_TEXTURE_2D, (this->TextureID));

	//Render textured quad
	glBegin(GL_QUADS);
	glTexCoord2f(0.f, 0.f); glVertex2f(0.f, 0.f);
	glTexCoord2f(1.f, 0.f); glVertex2f(Width, 0.f);
	glTexCoord2f(1.f, 1.f); glVertex2f(Width, Height);
	glTexCoord2f(0.f, 1.f); glVertex2f(0.f, Height);
	glEnd();

	glLoadIdentity();
}