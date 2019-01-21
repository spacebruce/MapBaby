#include "TileType.h"

TileType::TileType(const ResourceID ID) : Resource(ID)
{}

TileType::~TileType()
{}

TileType::TileType(const ResourceID ID, const Bitmap bitmap) : Resource(ID)
{
	this->bitmap = bitmap;
}

TileType::TileType(const Bitmap bitmap) : Resource()
{
	this->bitmap = bitmap;
}

Texture * TileType::getTexture()
{
	return &this->texture;
}

Bitmap & TileType::getBitmap()
{
	return this->bitmap;
}

void TileType::updateTexture(Palette& palette)
{
	this->texture.createFromBitmap(this->bitmap, palette);
}