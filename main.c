#include "image.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
	char *filename = argv[1];

	Image *image = loadImage(filename);
	Image *neg = negative(image);
	saveImage(neg, argv[2]);
}
