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

	Map(int width, int height);
	void setSize(int width, int height);

	int getWidth() const;
	int getHeight() const;
};