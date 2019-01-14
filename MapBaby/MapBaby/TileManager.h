#pragma once
#include <vector>
#include "Tile.h"

class TileManager
{
private:
	std::vector<Tile> tilePool;
public:
	TileManager();
	~TileManager();
};