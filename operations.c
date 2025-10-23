#include "operations.h"
#include "image.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Image *upscale(Image *input, int factor) {
    Image *output = malloc(sizeof(Image));

    // Copia header e metadata di base
    memcpy(output->header, input->header, 54);
    output->width = input->width * factor;
    output->height = input->height * factor;
    output->bitDepth = input->bitDepth;
	
	output->header[18] = input->width * factor;
	output->header[22] = input->height * factor;
	output->header[28] = input->bitDepth * factor;
    
// Alloca nuova matrice di pixel
    output->data = malloc(output->height * sizeof(unsigned char *));
    for (int i = 0; i < output->height; i++)
        output->data[i] = malloc(output->width * sizeof(unsigned char));

    // Algoritmo nearest-neighbor
    for (int i = 0; i < output->height; i++) {
        for (int j = 0; j < output->width; j++) {
            int srcY = i / factor;
            int srcX = j / factor;
            output->data[i][j] = input->data[srcY][srcX];
        }
    }

    return output;
}
