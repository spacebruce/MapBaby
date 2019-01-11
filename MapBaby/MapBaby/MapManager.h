#pragma once
#include <vector>
#include "Map.h"

class MapManager
{
private:
	std::vector<Map> mapPool;
	int current = -1;
public:
	MapManager();
	~MapManager();

	Map * getCurrentMap();
	Map * getMap(int index);

	void setCurrent(int index);
	void deselect();
	int getCurrent() const;
	void closeMap(int index);
	bool isCurrent(int index) const;

	int getCount() const;

	void newMap();
	void newMap(Map map);
};