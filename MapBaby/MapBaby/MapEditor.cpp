#include "MapEditor.h"

MapEditor::MapEditor()
{
}

MapEditor::~MapEditor()
{
}

void MapEditor::render()
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glRectf(-0.75f, 0.75f, 0.75f, -0.75f);
}