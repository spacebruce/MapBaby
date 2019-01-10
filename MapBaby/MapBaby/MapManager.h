#pragma once
#include <vector>
#include "Map.h"

class MapManager
{
private:
	std::vector<Map> mapPool;
public:
	MapManager();
	~MapManager();

	Map * getMap(std::size_t index);
	std::size_t getCount();
	void newMap();
};