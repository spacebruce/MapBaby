#include "DrawingHelpers.h"

void Drawing::DrawLine(float x, float y, float x2, float y2)
{
	glBegin(GL_LINES);
	glVertex3f(x, y, 0.0);
	glVertex3f(x2, y2, 0);
	glEnd();
}


void Drawing::DrawRectangleOutline(float x, float y, float x2, float y2)
{
	glBegin(GL_LINES);
	glVertex3f(x, y, 0.0);
	glVertex3f(x2, y, 0);
	glVertex3f(x2, y, 0.0);
	glVertex3f(x2, y2, 0);
	glVertex3f(x2, y2, 0.0);
	glVertex3f(x, y2, 0);
	glVertex3f(x, y2, 0.0);
	glVertex3f(x, y, 0);
	glEnd();
}