#pragma once

struct Map
{
	int Width = 12;
	int Height = 12;
	int TileSize = 16;

	Map() = default;
	Map(int width, int height)
	{
		this->setSize(width, height);
	}
	void setSize(int width, int height)
	{
		this->Width = width;
		this->Height = height;
	}
};