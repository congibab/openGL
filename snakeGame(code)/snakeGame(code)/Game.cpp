#include "Game.h"
#include "Map.h"
#include "Player.h"

Map map;
Player player;

void Game::Init()
{
	map.Init();
	player.Init(10,10);
}

void Game::update()
{

	map.SetStage(player.GetPos(), player_collision);
	map.SetStage(player.Gettemp_pos(), field_collision);
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