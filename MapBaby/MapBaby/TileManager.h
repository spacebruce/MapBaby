#pragma once
#include <memory>
#include <vector>
#include "TileType.h"
#include "Texture.h"

class TileManager
{
public:
	using SharedTile = std::shared_ptr<TileType>;
private:
	std::vector<SharedTile> tilePool;
public:
	TileManager();
	~TileManager();

	void createTile();

	TileType * getTile(const int index);
	int getCount() const;
};