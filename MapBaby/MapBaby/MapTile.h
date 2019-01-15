#pragma once

#include "ResourceID.h"

class MapTile
{
private:
	ResourceID::Type tileID;
public:
	MapTile();
	~MapTile();

	void setTile(const ResourceID::Type id);
	ResourceID::Type getTile() const;
};