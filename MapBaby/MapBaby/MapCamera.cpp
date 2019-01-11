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
	float mouseXnormal = Numbers::mapValue(mouseX, 0.0f, static_cast<float>(WindowWidth), 0.0f, 1.0f);
	float mouseYnormal = Numbers::mapValue(mouseY, 0.0f, static_cast<float>(WindowHeight), 0.0f, 1.0f);

	mouseX = Numbers::mapValue(mouseXnormal, 0.0f, 1.0f, left, right);
	mouseY = Numbers::mapValue(mouseYnormal, 0.0f, 1.0f, top, bottom);
}
