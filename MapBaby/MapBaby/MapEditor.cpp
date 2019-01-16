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
	if (map == nullptr)
		return;

	//Project!
	auto cameraBox = camera.getBox();
	glViewport(0, 0, (GLsizei)WindowWidth, (GLsizei)WindowHeight);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	glOrtho(cameraBox.left, cameraBox.right, cameraBox.bottom, cameraBox.top, -1.0f, +1.0f);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();


	//Draw stuff
	const int Width = map->getWidth();
	const int Height = map->getHeight();
	const int TileSize = map->getTileSize();

	const int WidthReal = Width * TileSize;
	const int HeightReal = Height * TileSize;
	
	/*
	Drawing::drawRectangleOutline(0, 0, WidthReal, HeightReal);
	for (int i = 0; i < Width; ++i)
	{
		Drawing::drawLine(i * TileSize, 0.0f, i * TileSize, HeightReal);
	}
	for (int i = 0; i < Height; ++i)
	{
		Drawing::drawLine(0.0f, i * TileSize, WidthReal, i * TileSize);
	}
	*/

	int clipLeft = static_cast<int>((cameraBox.left >= 0) ? (cameraBox.left / TileSize) : 0);
	int clipTop = static_cast<int>((cameraBox.top >= 0) ? (cameraBox.top / TileSize) : 0);
	int clipRight = static_cast<int>((cameraBox.right < WidthReal) ? ceil(cameraBox.right / TileSize) : Width);
	int clipBottom = static_cast<int>((cameraBox.bottom < HeightReal) ? ceil(cameraBox.bottom/ TileSize): Height);

	for (int x = clipLeft; x < clipRight; ++x)
	{
		for (int y = clipTop; y < clipBottom; ++y)
		{
			Drawing::drawRectangleOutline(x * TileSize, y * TileSize, (x + 1) * TileSize, (y + 1)*TileSize);
			/*
			ResourceID::Type tileID = map->getTile(x, y)->tileID;
			if(!tileID.invalid())
			{
				TileType * tile = tileManager->getTile(tileID);
				tile->getTexture()->testRender(x * TileSize, y * TileSize);
			}
			*/
		}
	}

	if (camera.isMouseTileValid())
	{
		float mx = camera.getMouseTileX() * TileSize;
		float my = camera.getMouseTileY() * TileSize;
		Drawing::drawLine(mx, my, mx + TileSize, my + TileSize);
		Drawing::drawLine(mx + TileSize, my, mx, my + TileSize);
	}
	
	//Unproject!
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
}

void MapEditor::changeMap(Map * map)
{
	this->map = map;
}