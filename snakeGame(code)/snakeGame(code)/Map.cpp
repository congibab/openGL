#include "Map.h"
#include <iostream>

void Map::Init()
{
	
}

void Map::update()
{
	
}

void Map::draw()
{
	for (int j = 0; j < column; j++)
	{
		for (int i = 0; i < row; i++)
		{
			if (i == 0 || i == (row-1) ||
				j == 0 || j == (column-1))
			{
				glBegin(GL_POLYGON);
				glColor3d(1.0, 0.0, 0.0);
			}

			else
			{
				glBegin(GL_LINE_LOOP);
				glColor3d(1.0, 1.0, 1.0);
			}
			
			glVertex2d(i - 0.5, j + 0.5);
			glVertex2d(i - 0.5, j - 0.5);
			glVertex2d(i + 0.5, j - 0.5);
			glVertex2d(i + 0.5, j + 0.5);
			glEnd();
		}
	}
}
