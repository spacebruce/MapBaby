#include "TileManager.h"

TileManager::TileManager()
{
}

TileManager::~TileManager()
{
}

void TileManager::createTile(TileType& tile)
{
	SharedTile newTile = std::make_shared<TileType>();
	Bitmap& bitmap = newTile.get()->bitmap;
	Palette& palette = tile.palette();

	bitmap = tile.bitmap;	//copy bitmap
	newTile.get()->updateTexture(palette);	//build new texture from that bitmap

	tilePool.emplace_back(newTile);
	tileLookup.emplace(std::make_pair(newTile.get()->getID(), newTile));
}

void TileManager::createTile(Palette &palette)
{
	SharedTile newTile = std::make_shared<TileType>();
	Texture * tex = &newTile.get()->texture;

	//dummy texture
	constexpr static int width = 16;
	constexpr static int height = 16;
	Bitmap& bitmap = newTile.get()->bitmap;

	for (int i = 0; i < (width * height); ++i)
	{
		bitmap.setPixel(i, i % palette.getSize());	//rotate through palette 
	}
	newTile.get()->updateTexture(palette);

	tilePool.emplace_back(newTile);
	tileLookup.emplace(std::make_pair(newTile.get()->getID(), newTile));
}

std::size_t TileManager::getSelectedIndex() const
{
	for (std::size_t i = 0; i < this->tilePool.size(); ++i)
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

void TileManager::setSelected(const std::size_t index)
{
	this->selectedTile = this->tilePool[index].get()->getID();
}

void TileManager::setSelected(const ResourceID id)
{
	this->selectedTile = id;
}

TileManager::SharedTile TileManager::getTile(const std::size_t index)
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

std::size_t TileManager::getCount() const
{
	return (this->tilePool.size());
}