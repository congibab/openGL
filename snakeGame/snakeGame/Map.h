#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>

#define column 20
#define row 20

class Map
{
private :
	int stage[column][row];
	//void main();

public :
	void Init();
	void Draw_Grid();

	int Getcolumn();
	int Getrow();
};

