#pragma once

#include  "ResourceID.h"
#include  "Resource.h"

#include "Texture.h"

class TileType : public Resource
{
private:
	Texture texture;
public:
	TileType() = default;
	TileType(const ResourceID::Type ID);
	~TileType();

	Texture * getTexture();
};