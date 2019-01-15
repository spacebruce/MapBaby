#pragma once
#include <memory>
#include <vector>
#include "Tile.h"
#include "Texture.h"

class TileManager
{
public:
	using SharedTile = std::shared_ptr<Tile>;
private:
	std::vector<SharedTile> tilePool;
public:
	TileManager();
	~TileManager();

	void createTile();

	Tile * getTile(const int index);
	int getCount() const;
};