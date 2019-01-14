#include "Tile.h"

Tile::Tile(const ResourceID::Type ID) : Resource(ID)
{}

Tile::~Tile()
{
}

Texture * Tile::getTexture()
{
	return &this->texture;
}
