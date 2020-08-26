#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <FreeImage.h>
#include <iostream>

#define column 20
#define row 20

class Game
{
private:
	void Check_Wall_collision();
	void Check_Item_collision();
public:
	void Init();
	void update();
	void draw();
	void Input(unsigned char key, int x, int y);
};

