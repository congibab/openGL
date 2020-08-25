#include "Map.h"
#include <iostream>

void Map::Init()
{
	for (int j = 0; j < column; j++)
	{
		for (int i = 0; i < row; i++)
		{
			if (i == 0 || i == (row - 1) ||
				j == 0 || j == (column - 1))
			{
				stage[i][j] = 1;
			}
			else
			{
				stage[i][j] = 0;
			}
		}
	}
}

void Map::update()
{
	for (int j = 0; j < column; j++)
	{
		for (int i = 0; i < row; i++)
		{
			std::cout << stage[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

}

void Map::draw()
{
	for (int j = 0; j < column; j++)
	{
		for (int i = 0; i < row; i++)
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
}

int* Map::GetStage()
{
	int arr[column][row];
	
	for (int j = 0; j < column; j++)
	{
		for (int i = 0; i < row; i++)
		{
			arr[i][j] = stage[i][j];
		}
	}

	return (int*)arr;
}
//
//static int arr[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
//return (int*)arr;