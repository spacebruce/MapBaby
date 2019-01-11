#include "DrawingHelpers.h"

void Drawing::drawLine(const float x, const float y, const float x2, const float y2)
{
	glBegin(GL_LINES);
	glVertex3f(x, y, 0.0);
	glVertex3f(x2, y2, 0);
	glEnd();
}

void Drawing::drawRectangleOutline(const float x, const float y, const float x2, const float y2)
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

void Drawing::drawCircleOutline(const float x, const float y, const float radius, const int resolution = 16)
{
	const float step = static_cast<float>(tau / resolution);
	glBegin(GL_LINE_LOOP);
	{
		float angle = 0;
		for (int i = 0; i <= resolution; ++i)
		{
			glVertex2f(x + std::cos(angle) * radius, y + std::sin(angle) * radius);
			angle += step;
		}
	}
	glEnd();
}