#include <iostream>

#include "Game.h"
#include "Map.h"
#include "Player.h"
#include "Item.h"

Map map;
Player player;
Item item;

bool Game::Check_Item_collision()
{
	if (player.GetPos().x == item.Getpos().x &&
		player.GetPos().y == item.Getpos().y)
	{
		item.Respawn();
		player.push_back();
		count++;
		return true;
	}
	return false;
}

void Game::Init()
{
	count = 0;
	GameOver = false;
	UIMassage = "GamePlaying";
	map.Init();
	item.Init(5, 5);
	player.Init(10,10);
	
}

void Game::update()
{
	if (GameOver) return;

	if(Check_Item_collision()) UIMassage = "Get Item = " + std::to_string(count);
	map.update();
	item.update();
	player.update();

	if (player.collision())
	{
		UIMassage = "GameOver";
		GameOver = true;
	}
}

void Game::draw()
{
	map.draw();
	item.draw();
	player.draw();
}

void Game::Input(unsigned char key, int x, int y)
{
	if (GameOver)
	{
		Init();
	}
	
	else
	{
		player.Input(key, x, y);
	}	
}