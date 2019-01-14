#pragma once

#include  "ResourceID.h"
#include  "Resource.h"

class Tile : public Resource
{
public:
	Tile() = default;
	Tile(const ResourceID::Type ID);
	~Tile();
};