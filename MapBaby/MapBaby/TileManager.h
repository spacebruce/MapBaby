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
	ResourceID selectedTile = ResourceID(0);

	std::vector<SharedTile> tilePool;
	std::map<ResourceID, SharedTile*> tileLookup;
public:
	TileManager();
	~TileManager();

	void createTile();

	int getSelectedIndex() const;
	ResourceID getSelectedID() const;
	void setSelected(const int index);
	void setSelected(const ResourceID id);

	TileType * getTile(const int index);
	TileType * getTile(const ResourceID lookup);

	int getCount() const;
};