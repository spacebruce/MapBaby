#include "Map.h"

Map::Map(const ResourceID ID, const std::string name, const int width, const int height) : Resource(ID), name(name)
{
	this->resize(width, height);
}

Map::Map(const std::string name, const int width, const int height) : name(name), Resource()
{
	this->resize(width, height);
}

Map::Map(const int width, const int height) : Resource()
{
	this->resize(width, height);
}

Map::Map(const ResourceID ID) : Resource(ID)
{
}

Map::Map(const ResourceID ID, const int width, const int height) : Resource(ID)
{
	this->resize(width, height);
}

void Map::resize(const int width, const int height) 
{
	this->width = std::max(width, 1);
	this->height = std::max(height, 1);

	tiles.resize(width);
	for (int i = 0; i < width; ++i)
	{
		tiles[i].resize(height);
	}
}

bool Map::isValidPosition(const int x, const int y) const
{
	return ((x >= 0) && (y >= 0) && (x < width) && (y < height));
}

MapTile * Map::getTile(const int x, const int y)
{
	if (!isValidPosition(x, y))
		return nullptr;
	return &tiles[x][y];
}

void Map::setTile(const int x, const int y, MapTile tile)
{
	if (!isValidPosition(x, y))
		return;
	tiles[x][y] = tile;
}

int Map::getWidth() const
{
	return this->width;
}
int Map::getHeight() const
{
	return this->height;
}

int Map::getTileSize() const
{
	return this->tileSize;
}

bool Map::isResizeSafe(const int newWidth, const int newHeight) const
{
	return ((newWidth >= width) && (newHeight >= height));
	//add tile checks later...
}