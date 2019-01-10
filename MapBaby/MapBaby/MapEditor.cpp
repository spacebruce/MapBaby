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
	glOrtho( 0.0, WindowWidth, WindowHeight, 0.0, 1.0, -1.0 );
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); 

	glTranslatef(0.0f, 0.0f, 0.0f);
	glPushMatrix();

	if (map == nullptr)
		return;

	//Draw stuff
	glColor3f(0.0f, 0.0f, 0.0f);
	glRectf(64, 64, 128, 128);
}

void MapEditor::changeMap(Map * map)
{
	this->map = map;
}