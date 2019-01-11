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

void MapCamera::updateMouse(const int WindowWidth, const int WindowHeight)
{
	//requires projection to be up to date!
	float mouseX, mouseY;
	{
		int mx, my;
		SDL_GetMouseState(&mx, &my);
		mouseX = static_cast<float>(mx);
		mouseY = static_cast<float>(my);
	}
	mouseX = Numbers::mapValue(mouseX, 0.0f, static_cast<float>(WindowWidth), left, right);
	mouseY = Numbers::mapValue(mouseY, 0.0f, static_cast<float>(WindowHeight), top, bottom);
}
