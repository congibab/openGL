#include "TextureManager.h"

GLuint TextureManager::LoadGLTextures(char const* filename)
{
	//IplImage *image1=cvLoadImage(¡°../../lena.png¡±,CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR);

	cv::Mat img = cv::imread(filename);

	//cvFlip(image1,NULL,0);

	cv::flip(img, img, 0);

	/******* «Æ«¯«¹«Á«ãíÂà÷ ****************/

	GLuint texture;
	glGenTextures(1, &texture);

	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,image1->width,image1->height, 0,GL_BGR_EXT,GL_UNSIGNED_BYTE,image1->imageData);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img.size().width, img.size().height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, img.data);

	//cvReleaseImage( &image1 );

	return texture;
}
