#include "TileType.h"

TileType::TileType(const ResourceID::Type ID) : Resource(ID)
{}

TileType::~TileType()
{
}

Texture * TileType::getTexture()
{
	return &this->texture;
}
