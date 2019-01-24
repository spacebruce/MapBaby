#pragma once

#include  "ResourceID.h"
#include  "Resource.h"

#include "Texture.h"
#include "Bitmap.h"

class TileType : public Resource
{
public:
	Bitmap bitmap;
	Texture texture;
	Palette palette;

	TileType() = default;
	TileType(const Bitmap bitmap);
	TileType(const ResourceID ID);
	TileType(const ResourceID ID, const Bitmap bitmap);
	TileType(const TileType& tile);	//copy

	~TileType();

	void changePalette(Palette& palette);
	void updateTexture(Palette& palette);
	void updateTexture();
};