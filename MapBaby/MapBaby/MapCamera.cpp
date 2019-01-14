#include "MapCamera.h"

MapCamera::MapCamera()
{
}

MapCamera::~MapCamera()
{
}

float MapCamera::getMouseX() const
{
	return this->mouseX;
}

float MapCamera::getMouseY() const
{
	return this->mouseY;
}

Numbers::Rectangle<float> MapCamera::getBox()
{
	auto box = Numbers::Rectangle<float>(left, right, top, bottom);
	return box;
}

int MapCamera::getMouseTileX() const
{
	return this->mouseTileX;
}

int MapCamera::getMouseTileY() const
{
	return this->mouseTileY;
}

bool MapCamera::isMouseTileValid() const
{
	return this->mouseTileValid;
}


void MapCamera::update(const int WindowWidth, const int WindowHeight, const Map *map, const bool CheckInput)
{
	updateOrtho(WindowWidth, WindowHeight);
	if ((CheckInput) && (map != nullptr))
		updateMouse(WindowWidth, WindowHeight, map);
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

void MapCamera::updateMouse(const int WindowWidth, const int WindowHeight, const Map * map)
{
	//requires projection to be up to date!
	int mx, my;
	SDL_GetMouseState(&mx, &my);
	this->mouseX = Numbers::mapValue(static_cast<float>(mx), 0.0f, static_cast<float>(WindowWidth), left, right);
	this->mouseY = Numbers::mapValue(static_cast<float>(my), 0.0f, static_cast<float>(WindowHeight), top, bottom);

	if ((mouseX < 0) || (mouseY < 0))
	{
		this->mouseTileX = -1;
		this->mouseTileY = -1;
	}
	else
	{
		this->mouseTileX = static_cast<int>(this->mouseX / map->getTileSize());
		this->mouseTileY = static_cast<int>(this->mouseY / map->getTileSize());
	}

	mouseTileValid = ((mouseTileX >= 0) && (mouseTileY >= 0) && (mouseTileX < map->getWidth()) && (mouseTileY < map->getHeight()));
}
