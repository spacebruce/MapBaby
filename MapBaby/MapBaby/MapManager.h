#pragma once
#include <vector>
#include "Map.h"

class MapManager
{
private:
	std::vector<Map> mapPool;
	Map * current;
public:
	MapManager();
	~MapManager();

	Map * getMap(std::size_t index);
	std::size_t getCount();
	void newMap();

	void closeMap(std::size_t index);

	void setCurrent(std::size_t index);
	Map * currentMap();
	bool isCurrent(std::size_t index);
};