#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "player.h"

#define column 20
#define row 20

#define wall_collision 1
#define player_collision 2
#define field_collision 0


class Map
{
private:
	int stage[column][row];
public:
	void Init();
	void update();
	void draw();
	
	int* GetStage();
	
	void SetStage(Vector2D pos, int collision) 
	{
		stage[pos.x][pos.y] = collision;
	};
};

