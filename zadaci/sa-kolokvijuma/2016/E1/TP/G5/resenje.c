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

typedef struct node_st {
    PIXEL data;
    struct node_st *next;
} NODE;


FILE *safe_fopen(char *name, char *mode);
void init_list(NODE **head, NODE **tail);
NODE *create_node(PIXEL p);
void add_on_end(NODE **head, NODE **tail, PIXEL p);
void delete_list(NODE **head, NODE **tail);
unsigned examine_image_header(FILE *in, unsigned char *header);
void read_image(FILE *in, NODE **head, NODE **tail);
void write_image(FILE *out, unsigned char *header, NODE *head);
void feature_detection(NODE *head, int offset);


int main(int num_args, char **args) {
    if(num_args != 4) {
        printf("USAGE: %s in.bmp out.bmp offset\n", args[0]);
        exit(1);
    }

    FILE *in = safe_fopen(args[1], "rb");
    FILE *out = safe_fopen(args[2], "wb");
    int offset = atoi(args[3]);

    unsigned char header[HEADER_SIZE];
    unsigned image_size = examine_image_header(in, header);

    NODE *head, *tail;
    init_list(&head, &tail);
    read_image(in, &head, &tail);

    feature_detection(head, offset);

    write_image(out, header, head);

    fclose(in);
    fclose(out);

    delete_list(&head, &tail);

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

void init_list(NODE **head, NODE **tail) {
    *head = NULL;
    *tail = NULL;
}

NODE *create_node(PIXEL p) {
    NODE *new = malloc(sizeof(NODE));

    if(new == NULL) {
        puts("Not enough RAM!");
        exit(EXIT_FAILURE);
    }

    new->data = p;
    new->next = NULL;

    return new;
}

void add_on_end(NODE **head, NODE **tail, PIXEL p) {
    NODE *new = create_node(p);

    if (*head != NULL) {
        (*tail)->next = new;
    } else {
        *head = new;
    }

    *tail = new;
}

void delete_list(NODE **head, NODE **tail) {
    NODE *temp = *head;

    while(*head != NULL) {
        temp = *head;
        *head = (*head)->next;

        temp->next = NULL;
        free(temp);
    }

    *tail = NULL;
}

unsigned examine_image_header(FILE *in, unsigned char *header) {
    fread(header, sizeof(unsigned char), HEADER_SIZE, in);

    unsigned width = *(unsigned *) &header[WIDTH_POS];
    unsigned height = *(unsigned *) &header[HEIGHT_POS];

    return width * height;
}

void read_image(FILE *in, NODE **head, NODE **tail) {
    PIXEL p;

    while (fread(&p, sizeof(PIXEL), 1, in) != 0) {
        add_on_end(head, tail, p);
    }
}

void write_image(FILE *out, unsigned char *header, NODE *head) {
    fwrite(header, sizeof(unsigned char), HEADER_SIZE, out);

    while(head != NULL) {
        fwrite(&(head->data), sizeof(PIXEL), 1, out);

        head = head->next;
    }
}

void feature_detection(NODE *head, int offset) {
    while(head != NULL) {
        head->data.R |= head->data.G;
        head->data.G >>= offset;
        head->data.B = ~head->data.B;

        head = head->next;
    }
}
