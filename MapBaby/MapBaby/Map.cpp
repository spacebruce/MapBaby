#include "Map.h"

Map::Map(int width, int height)
{
	this->setSize(width, height);
}

void Map::setSize(int width, int height)
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

bool Map::isResizeSafe(int newWidth, int newHeight) const
{
	return ((newWidth >= Width) && (newHeight >= Height));
	//add tile checks later...
}