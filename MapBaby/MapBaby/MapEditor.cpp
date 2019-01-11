#include "MapEditor.h"

MapEditor::MapEditor()
{
}

MapEditor::MapEditor(Map * map)
{
	this->map = map;
}

MapEditor::~MapEditor()
{
}

void MapEditor::render(const int WindowWidth, const int WindowHeight)
{
	//Set the viewport
	glViewport( 0, 0, WindowWidth, WindowHeight);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 

	float zoom = (camera.zoom / 100.0f);
	float left = camera.x - (WindowWidth / 2) / zoom;
	float top = camera.y - (WindowHeight / 2) / zoom;
	float right = camera.x + (WindowWidth / 2) / zoom;
	float bottom = camera.y + (WindowHeight / 2) / zoom;

	glOrtho( left, right, top, bottom , 1.0, -1.0 );
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); 

	glTranslatef(0.0f, 0.0f, 0.0f);
	glPushMatrix();

	if (map == nullptr)
		return;

	//Draw stuff
	const int Width = 12;
	const int Height = 8;
	const int TileSize = 16;
	const int WidthReal = Width * TileSize;
	const int HeightReal = Height * TileSize;

	Drawing::drawRectangleOutline(0, 0, WidthReal, HeightReal);
	for (int i = 0; i < Width; ++i)
	{
		Drawing::drawLine(i * TileSize, 0.0f, i * TileSize, HeightReal);
	}
	for (int i = 0; i < Height; ++i)
	{
		Drawing::drawLine(0.0f, i * TileSize, WidthReal, i * TileSize);
	}
}

void MapEditor::changeMap(Map * map)
{
	this->map = map;
}