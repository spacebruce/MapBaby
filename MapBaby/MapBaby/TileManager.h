#pragma once
#include <vector>
#include "Tile.h"
#include "Texture.h"

class TileManager
{
private:
	std::vector<Tile> tilePool;
public:
	TileManager();
	~TileManager();

	void createTile();

	Tile * getTile(const int index);
	int getCount() const;
};