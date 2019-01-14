#pragma once
#include "MathsHelpers.h"

#include "ResourceID.h"
#include "Resource.h"

class Map : public Resource
{
private:
	int Width = 12;
	int Height = 12;
	int TileSize = 16;
public:
	Map() = default;
	Map(const int width, const int height);
	Map(const ResourceID::Type ID);
	Map(const ResourceID::Type ID, const int width, const int height);

	void setSize(const int width, const int height);

	int getWidth() const;
	int getHeight() const;
	int getTileSize() const;

	bool isResizeSafe(const int newWidth, const int newHeight) const;
};