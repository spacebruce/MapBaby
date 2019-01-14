#include "MapEditor.h"

MapEditor::MapEditor(TileManager& tileManager)
{
	this->tileManager = &tileManager;
}

MapEditor::~MapEditor()
{
}

void MapEditor::update(const int WindowWidth, const int WindowHeight, const bool CheckInput)
{
	camera.update(WindowWidth, WindowHeight, map, CheckInput);
}

void MapEditor::render(const int WindowWidth, const int WindowHeight)
{
	//Set the viewport
	glViewport( 0, 0, WindowWidth, WindowHeight);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	
	auto cameraBox = camera.getBox();
	glOrtho(cameraBox.left, cameraBox.right, cameraBox.bottom, cameraBox.top, 1.0f, -1.0f);
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

	if (tileManager->getCount() > 0)
	{
		tileManager->getTile(0)->getTexture()->testRender(0, 0);
	}

	if (camera.isMouseTileValid())
	{
		float mx = camera.getMouseTileX() * TileSize;
		float my = camera.getMouseTileY() * TileSize;
		Drawing::drawLine(mx, my, mx + TileSize, my + TileSize);
		Drawing::drawLine(mx + TileSize, my, mx, my + TileSize);
	}
}

void MapEditor::changeMap(Map * map)
{
	this->map = map;
}