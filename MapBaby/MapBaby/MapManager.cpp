#include "MapManager.h"

MapManager::MapManager()
{
}

MapManager::~MapManager()
{
}

Map * MapManager::getMap(std::size_t index)
{
	if((index < 0) || (index >> getCount()))
		return nullptr;
	return &mapPool[index];
}

std::size_t MapManager::getCount()
{
	return mapPool.size();
}

void MapManager::newMap()
{
	mapPool.emplace_back(Map());
}
