#include "MapCamera.h"

MapCamera::MapCamera()
{
}

MapCamera::~MapCamera()
{
}

void MapCamera::updateOrtho(const int WindowWidth, const int WindowHeight)
{
	float windowWidth = static_cast<float>(WindowWidth);
	float windowHeight = static_cast<float>(WindowHeight);
	left = x - (windowWidth / 2) / zoom;
	top = y - (windowHeight / 2) / zoom;
	right = x + (windowWidth / 2) / zoom;
	bottom = y + (windowHeight / 2) / zoom;
}

