#include "MapManager.h"

MapManager::MapManager()
{
}

MapManager::~MapManager()
{
}

Map * MapManager::getCurrentMap()
{
	return getMap(getCurrent());
}

Map * MapManager::getMap(int index)
{
	if ((index < 0) || (index > getCount()))
		return nullptr;
	else
		return &(mapPool[index]);
}

void MapManager::setCurrent(int index)
{
	this->current = index;
}
void MapManager::deselect()
{
	this->current = -1;
}
int MapManager::getCurrent()
{
	return this->current;
}

int MapManager::getCount()
{
	return (mapPool.size());
}

void MapManager::newMap()
{
	mapPool.emplace_back(Map());
}

void MapManager::newMap(Map map)
{
	mapPool.emplace_back(map);
}

bool MapManager::isCurrent(int index)
{
	return (index == this->current);
}