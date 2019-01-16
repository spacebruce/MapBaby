#pragma once
#include <memory>
#include <vector>
#include <map>
#include "TileType.h"
#include "ResourceID.h"
#include "Texture.h"

class TileManager
{
public:
	using SharedTile = std::shared_ptr<TileType>;
private:
	std::vector<SharedTile> tilePool;
	std::map<ResourceID, SharedTile*> tileLookup;
public:
	TileManager();
	~TileManager();

	void createTile();

	TileType * getTile(const int index);
	TileType * getTile(const ResourceID lookup);

	int getCount() const;
};