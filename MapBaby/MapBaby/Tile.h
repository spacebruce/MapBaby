#pragma once

#include  "ResourceID.h"
#include  "Resource.h"

#include "Texture.h"

class Tile : public Resource
{
private:
	Texture texture;
public:
	Tile() = default;
	Tile(const ResourceID::Type ID);
	~Tile();

	Texture * getTexture();
};