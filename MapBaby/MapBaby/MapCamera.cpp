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

	float zoomPercent = zoom / 100.0f;
	left = x - (windowWidth / 2) / zoomPercent;
	top = y - (windowHeight / 2) / zoomPercent;
	right = x + (windowWidth / 2) / zoomPercent;
	bottom = y + (windowHeight / 2) / zoomPercent;
}

void MapCamera::updateMouse(const int WindowWidth, const int WindowHeight, const Map &map)
{
	//requires projection to be up to date!
	int mx, my;
	SDL_GetMouseState(&mx, &my);
	this->mouseX = Numbers::mapValue(static_cast<float>(mx), 0.0f, static_cast<float>(WindowWidth), left, right);
	this->mouseY = Numbers::mapValue(static_cast<float>(my), 0.0f, static_cast<float>(WindowHeight), top, bottom);

	this->mouseTileX = static_cast<int>(this->mouseX / map.TileSize);
	this->mouseTileY = static_cast<int>(this->mouseY / map.TileSize);
}
