#include "TileType.h"

TileType::TileType(const ResourceID ID) : Resource(ID)
{}

TileType::~TileType()
{}

TileType::TileType(const ResourceID ID, const Bitmap bitmap) : Resource(ID)
{
	this->bitmap = bitmap;
}

TileType::TileType(const TileType & tile)
{
	this->bitmap = tile.bitmap;
}

TileType::TileType(const Bitmap bitmap) : Resource()
{
	this->bitmap = bitmap;
}

Texture * TileType::getTexture()
{
	return &this->texture;
}

void TileType::changePalette(Palette& palette)
{
	this->palette = palette;
}

void TileType::updateTexture(Palette& palette)
{
	this->changePalette(palette);
	this->texture.createFromBitmap(this->bitmap, this->palette);
}

void TileType::updateTexture()
{
	this->texture.createFromBitmap(this->bitmap, this->palette);
}