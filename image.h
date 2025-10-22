#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>

typedef struct {
	unsigned char header[54];
	unsigned char colorTable[1024];
	unsigned char **data;
	int bitDepth;
	int width;
	int height;
} Image;

Image *loadImage(const char* pathToImage);
void saveImage(Image *image, const char *pathToImage);
void printBuffer(Image *image);
void freeImage(Image *image);

Image *copyImage(Image *from);
Image *negative(Image *from);

#endif
