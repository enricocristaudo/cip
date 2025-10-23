#include "image.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Image* loadImage(const char* pathToImage) {
	FILE *streamIn = fopen(pathToImage, "rb");
	size_t s = sizeof(unsigned char);	

	Image *image = malloc(sizeof(Image));

	fread(image->header, s, 54, streamIn);
	
	image->width = *(int*)&image->header[18];
	image->height = *(int*)&image->header[22];
	image->bitDepth = *(int*)&image->header[28];

	if(image->bitDepth <= 8)
		fread(image->colorTable, s, 1024, streamIn);
	
	image->data = malloc(image->height * sizeof(unsigned char *));
	for(int i=0; i<image->height; i++) { 
		image->data[i] = malloc(image->width * s);
		fread(image->data[i], s, image->width, streamIn);
	}
	fclose(streamIn);
	return image;
}

void saveImage(Image *image, const char *pathToImage) {
	FILE *output = fopen(pathToImage, "wb");
	size_t s = sizeof(unsigned char);	

	printf("%d\n", image->width);

	fwrite(image->header, s, 54, output);
	if(image->bitDepth <= 8)
		fwrite(image->colorTable, s, 1024, output);
	
	for(int i=0; i<image->height; i++)
		fwrite(image->data[i], s, image->width, output);
	fclose(output);
}

Image *copyImage(Image *from) {
	Image *copied = malloc(sizeof(Image));
	memcpy(copied, from, sizeof(Image));
	return copied;
}

void printBuffer(Image *image) {
	for(int i=0; i<image->width; i++) {
		for(int j=0; j<image->height; j++) {
			printf("%d ", (int)image->data[i][j]);	
		}
		printf("\n");
	}
} 

void freeImage(Image* image) {
	if(image) {
		free(image->data);
		free(image);
	}
}
