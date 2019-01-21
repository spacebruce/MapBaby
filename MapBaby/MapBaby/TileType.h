#pragma once

#include  "ResourceID.h"
#include  "Resource.h"

#include "Texture.h"
#include "Bitmap.h"

class TileType : public Resource
{
private:
	Bitmap bitmap;
	Texture texture;
public:
	TileType() = default;
	TileType(const Bitmap bitmap);
	TileType(const ResourceID ID);
	TileType(const ResourceID ID, const Bitmap bitmap);
	~TileType();

	Texture * getTexture();
};