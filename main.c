#include "image.h"
#include "filters.h"
#include "operations.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
	char *filename = argv[1];

	Image *image = loadImage(filename);
	Image *up = upscale(image, 2);
	saveImage(up, argv[2]);
}
