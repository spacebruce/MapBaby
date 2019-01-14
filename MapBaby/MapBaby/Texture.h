#pragma once

class Texture
{
private:
	int Width, Height;
public:
	Texture();
	~Texture();

	int getWidth() const;
	int getHeight() const;
};

