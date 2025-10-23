#include "image.h"
#include "filters.h"
#include <stdio.h>

Image *negative(Image *from) {
	Image *result = copyImage(from);
	for(int i=0; i<from->height; i++) {
		for(int j=0; j<from->width; j++) {
			result->data[i][j] = 255 - from->data[i][j];
		}
	}
	return result;
}

