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

void MapEditor::update(const int WindowWidth, const int WindowHeight)
{
	camera.updateOrtho(WindowWidth, WindowHeight);

	if(map != nullptr)
		camera.updateMouse(WindowWidth, WindowHeight, *map);
}

void MapEditor::render(const int WindowWidth, const int WindowHeight)
{
	//Set the viewport
	glViewport( 0, 0, WindowWidth, WindowHeight);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	
	glOrtho(camera.left, camera.right, camera.bottom, camera.top, 1.0f, -1.0f);
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); 

	glTranslatef(0.0f, 0.0f, 0.0f);
	glPushMatrix();

	if (map == nullptr)
		return;

	//Draw stuff
	const int Width = map->getWidth();
	const int Height = map->getHeight();
	const int TileSize = map->getTileSize();

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

	if (camera.mouseTileValid)
	{
		float mx = camera.mouseTileX * TileSize;
		float my = camera.mouseTileY * TileSize;
		Drawing::drawLine(mx, my, mx + TileSize, my + TileSize);
		Drawing::drawLine(mx + TileSize, my, mx, my + TileSize);
	}
}

void MapEditor::changeMap(Map * map)
{
	this->map = map;
}