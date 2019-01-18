#pragma once

#include "ResourceID.h"

struct MapTile
{
	ResourceID tileID = ResourceID(0);

	MapTile() = default;
	MapTile(ResourceID id) 
	{
		this->tileID = id;
	};
};