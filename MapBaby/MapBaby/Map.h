#pragma once

#include  "MathsHelpers.h"

class Map
{
private:
	int Width = 12;
	int Height = 12;
	int TileSize = 16;
public:
	Map() = default;

	Map(const int width, const int height);
	void setSize(const int width, const int height);

	int getWidth() const;
	int getHeight() const;
	int getTileSize() const;

	bool isResizeSafe(const int newWidth, const int newHeight) const;
};