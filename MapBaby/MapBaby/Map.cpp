#include "Map.h"

ResourceID::Type Map::getID()
{
	return this->ID;
}

Map::Map(const int width, const int height)
{
	this->setSize(width, height);
}

void Map::setSize(const int width, const int height)
{
	this->Width = Numbers::max(width, 1);
	this->Height = Numbers::max(height, 1);
}

int Map::getWidth() const
{
	return this->Width;
}
int Map::getHeight() const
{
	return this->Height;
}

int Map::getTileSize() const
{
	return this->TileSize;
}

bool Map::isResizeSafe(const int newWidth, const int newHeight) const
{
	return ((newWidth >= Width) && (newHeight >= Height));
	//add tile checks later...
}