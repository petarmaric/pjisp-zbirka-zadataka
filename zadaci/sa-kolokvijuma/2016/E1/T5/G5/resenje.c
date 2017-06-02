#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HEADER_SIZE 54
#define WIDTH_POS 18
#define HEIGHT_POS 22

typedef struct pixel_st {
    unsigned char B;
    unsigned char G;
    unsigned char R;
} PIXEL;


FILE *safe_fopen(char *name, char *mode);
void *safe_calloc(size_t nmemb, size_t size);
unsigned examine_image_header(FILE *in, unsigned char *header);
void read_image(FILE *in, PIXEL *pixels, unsigned image_size);
void write_image(FILE *out, unsigned char *header, PIXEL *pixels,
unsigned image_size);
void improve_truth(PIXEL *pixels, unsigned image_size, double truth_factor);


int main(int num_args, char **args) {
    if(num_args != 4) {
        printf("USAGE: %s in.bmp out.bmp truth_factor\n", args[0]);
        exit(1);
    }

    FILE *in = safe_fopen(args[1], "rb");
    FILE *out = safe_fopen(args[2], "wb");
    double truth_factor = atof(args[3]);

    unsigned char *header = safe_calloc(HEADER_SIZE, sizeof(unsigned char));
    unsigned image_size = examine_image_header(in, header);

    PIXEL *pixels = safe_calloc(image_size, sizeof(PIXEL));
    read_image(in, pixels, image_size);

    improve_truth(pixels, image_size, truth_factor);

    write_image(out, header, pixels, image_size);

    fclose(in);
    fclose(out);

    free(header);
    free(pixels);

    return 0;
}

FILE *safe_fopen(char *name, char *mode) {
    FILE *pf = fopen(name, mode);

    if(pf == NULL) {
        printf("File %s could not be opened!\n", name);
        exit(EXIT_FAILURE);
    }

    return pf;
}

void *safe_calloc(size_t nmemb, size_t size) {
    void *new = calloc(nmemb, size);

    if(new == NULL) {
        puts("Not enough RAM!");
        exit(EXIT_FAILURE);
    }

    return new;
}

unsigned examine_image_header(FILE *in, unsigned char *header) {
    fread(header, sizeof(unsigned char), HEADER_SIZE, in);

    unsigned width = *(unsigned *) &header[WIDTH_POS];
    unsigned height = *(unsigned *) &header[HEIGHT_POS];

    return width * height;
}

void read_image(FILE *in, PIXEL *pixels, unsigned image_size) {
    fread(pixels, sizeof(PIXEL), image_size, in);
}

void write_image(FILE *out, unsigned char *header, PIXEL *pixels,
unsigned image_size) {
    fwrite(header, sizeof(unsigned char), HEADER_SIZE, out);
    fwrite(pixels, sizeof(PIXEL), image_size, out);
}

void improve_truth(PIXEL *pixels, unsigned image_size, double truth_factor) {
    unsigned i;
    for(i=0; i<image_size; i++) {
        pixels[i].R = pixels[i].R * (1 - truth_factor) + 0xFC * truth_factor;
        pixels[i].G = pixels[i].G * (1 - truth_factor) + 0x89 * truth_factor;
        pixels[i].B = pixels[i].B * (1 - truth_factor) + 0xAC * truth_factor;
    }
}
