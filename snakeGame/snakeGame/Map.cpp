#include "Map.h"
#include "player.h"



//void Map::main()
//{
//	player _player;
//	Vector2D player_pos = _player.GetplayerPos();
//
//	void Init();
//	
//	for (int i = 0; i < column; i++)
//	{
//		for (int j = 0; j < row; j++)
//		{
//			if (player_pos.x == i || player_pos.y == j)
//			{
//				stage[i][j] = 2;
//			}
//			
//			else
//			{
//				stage[i][j] = 0;
//			}
//		}
//	}
//}

/// <summary>
/// 0 = field 1 = Wall  2 = player
/// </summary>
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
}

int Map::Getrow()
{
	return row;
}

int Map::Getcolumn()
{
	return column;
}

