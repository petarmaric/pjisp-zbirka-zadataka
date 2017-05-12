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
unsigned examine_image_header(FILE *in, unsigned char *header);
void read_image(FILE *in, PIXEL *pixels, unsigned image_size);
void write_image(FILE *out, unsigned char *header, PIXEL *pixels,
unsigned image_size);
void fix_colors(PIXEL *pixels, unsigned image_size);


int main(int num_args, char **args) {
    if(num_args != 3) {
        printf("USAGE: %s in.bmp out.bmp", args[0]);
        exit(1);
    }

    FILE *in = safe_fopen(args[1], "rb");
    FILE *out = safe_fopen(args[2], "wb");

    unsigned char header[HEADER_SIZE];
    unsigned image_size = examine_image_header(in, header);

    PIXEL pixels[image_size];
    read_image(in, pixels, image_size);

    fix_colors(pixels, image_size);

    write_image(out, header, pixels, image_size);

    fclose(in);
    fclose(out);

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

void fix_colors(PIXEL *pixels, unsigned image_size) {
    unsigned i;
    unsigned char tmp;

    for(i=0; i<image_size; i++) {
        pixels[i].B ^= pixels[i].R;
    }
}
