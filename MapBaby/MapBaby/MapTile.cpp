#include "Tile.h"

MapTile::MapTile()
{
}

MapTile::~MapTile()
{
}

void MapTile::setTile(const ResourceID::Type id)
{
	this->tileID = id;
}

ResourceID::Type MapTile::getTile() const
{
	return this->tileID;
}
