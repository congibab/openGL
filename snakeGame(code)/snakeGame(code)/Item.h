#pragma once
#include <random>
#include "player.h"
class Item
{
private:
	Vector2D pos;
	std::random_device rnd;
public:
	void Init(GLint x, GLint y);
	void update();
	void draw();
	void Respawn();

	Vector2D Getpos() { return pos; }
	void Setpos(Vector2D position) { pos = position; }
};

