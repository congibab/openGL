#include "Map.h"

void Map::Init()
{
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (i == 0 || i == (row - 1) ||
				j == 0 || j == (column - 1))
			{
				stage[i][j] == 1;
			}
			else
			{
				stage[i][j] == 0;
			}
			
		}
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="column"></param>
/// <param name="row"></param>
void Map::Draw_Grid()
{
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (i == 0 || i == (row - 1) || 
				j == 0 || j == (column - 1))
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
	glFinish();
}
