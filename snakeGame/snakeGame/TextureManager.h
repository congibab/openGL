#pragma once

//**********************************************
//Singleton Texture Manager class
//Written by Ben English
//benjamin.english@oit.edu
//
//For use with OpenGL and the FreeImage library
//**********************************************
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <FreeImage.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>



class TextureManager
{
public:
	GLuint CreateTexture(char const* filename);
	GLuint LoadGLTextures(char const* filename);

};

