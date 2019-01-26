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
	std::map<ResourceID, SharedTile> tileLookup;
public:
	TileManager();
	~TileManager();

	void createTile(TileType & tile);	//copies tile in
	void createTile(Palette& palette);

	void deleteTile(SharedTile & tile);

	std::size_t getSelectedIndex() const;
	ResourceID getSelectedID() const;
	void setSelected(const std::size_t index);
	void setSelected(const ResourceID id);

	SharedTile getTile(const std::size_t index);
	SharedTile getTile(const ResourceID lookup);

	std::size_t getCount() const;
};