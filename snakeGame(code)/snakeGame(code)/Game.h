#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <FreeImage.h>
#include <iostream>
#include <string>

#define column 20
#define row 20

class Game
{
private:
	int count;
	std::string UIMassage;
	bool GameOver;

	bool Check_Item_collision();
public:
	void Init();
	void update();
	void draw();
	void Input(unsigned char key, int x, int y);
	std::string Get_UIMassage() { return UIMassage; };
};

