#pragma once
#include <vector>
#include <algorithm>
#include "MathsHelpers.h"

#include "MapTile.h"
#include "ResourceID.h"
#include "Resource.h"

class Map : public Resource
{
private:
	std::vector<std::vector<MapTile>> tiles;
	int width = 12;
	int height = 12;
	int tileSize = 16;
public:
	Map() = default;
	Map(const int width, const int height);
	Map(const ResourceID::Type ID);
	Map(const ResourceID::Type ID, const int width, const int height);

	void resize(const int width, const int height);

	bool isValidPosition(const int x, const int y) const;

	MapTile * getTile(const int x, const int y);
	void setTile(const int x, const int y, MapTile * tile);

	int getWidth() const;
	int getHeight() const;
	int getTileSize() const;

	bool isResizeSafe(const int newWidth, const int newHeight) const;
};