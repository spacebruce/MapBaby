#include "MapManager.h"

MapManager::MapManager()
{
}

MapManager::~MapManager()
{
}

Map * MapManager::getCurrentMap()
{
	return this->getMap(this->getCurrent());
}

Map * MapManager::getMap(int index)
{
	if ((index < 0) || (index > this->getCount()))
		return nullptr;
	else
		return &(this->mapPool[index]);
}

void MapManager::setCurrent(int index)
{
	this->current = index;
}
void MapManager::deselect()
{
	this->current = -1;
}
int MapManager::getCurrent() const
{
	return this->current;
}

void MapManager::closeMap(int index)
{
	if ((index < 0) || (index > this->getCount()))
		return;
	this->mapPool.erase(this->mapPool.begin() + index);
	if (index == this->current)
	{
		this->deselect();
	}
}

int MapManager::getCount() const
{
	return (this->mapPool.size());
}

void MapManager::newMap()
{
	this->mapPool.emplace_back(Map());
}

void MapManager::newMap(Map map)
{
	this->mapPool.emplace_back(map);
}

bool MapManager::isCurrent(const int index) const
{
	return (index == this->current);
}