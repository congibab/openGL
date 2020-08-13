#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#include <GL/glew.h>

class Common
{
private:

public:
	std::string readFile(const char* filePath);
	GLuint loadShader(const char* vertex_path, const char* fragment_path);
};

