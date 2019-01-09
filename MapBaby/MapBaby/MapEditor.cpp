#include "MapEditor.h"

MapEditor::MapEditor()
{
}

MapEditor::~MapEditor()
{
}

void MapEditor::render(const int WindowWidth, const int WindowHeight)
{
	//Set the viewport
	glViewport( 0.f, 0.f, static_cast<float>(WindowWidth), static_cast<float>(WindowHeight));
	glMatrixMode( GL_PROJECTION ); 
	glLoadIdentity(); 
	glOrtho( 0.0, 1280, 720, 0.0, 1.0, -1.0 ); 
	glMatrixMode( GL_MODELVIEW ); 
	glLoadIdentity(); 

	//Draw stuff
	glColor3f(0.0f, 0.0f, 0.0f);
	glRectf(64, 64, 128, 128);
}