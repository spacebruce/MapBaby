#include "MapManager.h"

MapManager::MapManager()
{
}

MapManager::~MapManager()
{
}

Map * MapManager::getMap(std::size_t index)
{
	if((index < 0) || (index > getCount()))
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

void MapManager::closeMap(std::size_t index)
{
	if ((index >= 0) && (index < getCount()))
	{
		mapPool.erase(mapPool.begin() + index);
	}
}

void MapManager::setCurrent(std::size_t index)
{
	current = getMap(index);
}

Map * MapManager::currentMap()
{
	return current;
}

bool MapManager::isCurrent(std::size_t index)
{
	return (getMap(index) == currentMap());
}