#include "TileManager.h"

TileManager::TileManager()
{
}

TileManager::~TileManager()
{
}

void TileManager::createTile(Palette * palette)
{
	SharedTile newTile = std::make_shared<TileType>();
	Texture * tex = newTile.get()->getTexture();

	//dummy texture
	constexpr static int width = 16;
	constexpr static int height = 16;
	std::uint8_t bitmap[width * height];

	for (int i = 0; i < (width * height); ++i)
	{
		bitmap[i] = i % (palette->getSize() + 1);
	}
	tex->createFromBitmap(width, height, bitmap, palette);

	tilePool.emplace_back(newTile);
	tileLookup.emplace(std::make_pair(newTile.get()->getID(), newTile));
}

int TileManager::getSelectedIndex() const
{
	for (int i = 0; i < this->tilePool.size(); ++i)
	{
		if (this->tilePool[i].get()->getID() == this->selectedTile)
			return i;
	}
	return -1;
}

ResourceID TileManager::getSelectedID() const
{
	return selectedTile;
}

void TileManager::setSelected(const int index)
{
	this->selectedTile = this->tilePool[index].get()->getID();
}

void TileManager::setSelected(const ResourceID id)
{
	this->selectedTile = id;
}

TileManager::SharedTile TileManager::getTile(const int index)
{
	if ((index < 0) || (index > this->getCount()))
		return nullptr;
	return (this->tilePool[index]);
}

TileManager::SharedTile TileManager::getTile(const ResourceID lookup)
{
	if (tileLookup.count(lookup) == 0)
		return nullptr;
	return (this->tileLookup[lookup]);
}

int TileManager::getCount() const
{
	return (this->tilePool.size());
}