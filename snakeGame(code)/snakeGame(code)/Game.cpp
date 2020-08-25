#include "Game.h"
#include "Map.h"
#include "Player.h"

Map map;
Player player;

void Game::Check_Wall_collision()
{
	Vector2D temp = player.GetPos();
	Vector2D test = player.GetDir();
	if (temp.x > column - 3 && test.x == 1) temp.x = 0;
	else if (temp.y > row - 3 && test.y == 1) temp.y = 0;
	else if (temp.x < 2 && test.x == -1) temp.x = column - 1;
	else if (temp.y < 2 && test.y == -1) temp.y = row - 1;
	player.SetPos(temp);
}

void Game::Init()
{
	map.Init();
	player.Init(10,10);
}

void Game::update()
{

	map.SetStage(player.GetPos(), player_collision);
	map.SetStage(player.Gettemp_pos(), field_collision);

	Check_Wall_collision();

	map.update();
	player.update();
	//int* _stage = map.GetStage();
}

void Game::draw()
{
	map.draw();
	player.draw();
}

void Game::Input(unsigned char key, int x, int y)
{
	player.Input(key, x, y);
}