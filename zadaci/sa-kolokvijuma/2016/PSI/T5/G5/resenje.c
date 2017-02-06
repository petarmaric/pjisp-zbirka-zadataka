#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BASE_CAPACITY 10

#define MAX_NAME 21
#define MAX_STATE 6

typedef struct {
    unsigned contestant_number;
    char first_name[MAX_NAME];
    char last_name[MAX_NAME];
    char state[MAX_STATE];
} LOG_ENTRY;

typedef struct {
    LOG_ENTRY *pa;
    int capacity;
} DYN_ARRAY;

typedef struct {
    LOG_ENTRY *ptop;
    DYN_ARRAY host;
} STACK;

FILE *safe_fopen(const char *, const char *);
void read_file(FILE *, STACK []);
int print_in_file(FILE *, STACK *);

void init_array(DYN_ARRAY *);
void resize_array(DYN_ARRAY *, int);
void destroy_array(DYN_ARRAY *);

void init_stack(STACK *);
void resize_stack(STACK *, int);
int is_full(STACK);
int is_empty(STACK);
void push(STACK *, LOG_ENTRY);
LOG_ENTRY *pop(STACK *);
LOG_ENTRY peek(STACK);
void destroy_stack(STACK *);

STACK reverse(STACK);

int main(int args_num, char **args) {
    if(args_num != 4) {
        puts("Invalid program call. Example: ./a.out log.txt 3 7");
        exit(EXIT_FAILURE);
    }

    int i, num_of_contestants = atoi(args[2]);
    STACK contestants[num_of_contestants];

    for(i = 0;i < num_of_contestants;i++) {
        init_stack(&contestants[i]);
    }

    // a)

    FILE *pin = safe_fopen(args[1], "r");

    read_file(pin, contestants);
    fclose(pin);

    // b)

    STACK reversed_contestants[num_of_contestants];

    for(i = 0;i < num_of_contestants;i++) {
        reversed_contestants[i] = reverse(contestants[i]);
    }

    // c)

    FILE *pout;
    char filename[strlen(args[2]) + 2 * MAX_NAME + 2 + strlen(".txt") + 1];
    LOG_ENTRY temp;
    int step_count;

    for(i = 0;i < num_of_contestants;i++) {
        temp = peek(reversed_contestants[i]);
        sprintf(filename, "%u_%s_%s.txt", temp.contestant_number,
                                          temp.first_name,
                                          temp.last_name);
        pout = safe_fopen(filename, "w");
        step_count = print_in_file(pout, &reversed_contestants[i]);

        if(step_count < atoi(args[3])) {
            printf("%s %s\n", temp.first_name, temp.last_name);
        }

        fclose(pout);
    }

    for(i = 0;i < num_of_contestants;i++) {
        destroy_stack(&reversed_contestants[i]);
        destroy_stack(&contestants[i]);
    }

    return EXIT_SUCCESS;
}

FILE *safe_fopen(const char *name, const char *mode) {
    FILE *pf = fopen(name, mode);

    if(pf == NULL) {
        printf("File %s could not be opened. Program will now exit.\n", name);
        exit(EXIT_FAILURE);
    }

    return pf;
}

void read_file(FILE *pin, STACK contestants[]) {
    LOG_ENTRY temp;

    while(fscanf(pin, "%u %s %s %s", &temp.contestant_number,
                                     temp.first_name,
                                     temp.last_name,
                                     temp.state) != EOF) {
        if(strcmp(temp.state, "STOP") == 0) {
            while(strcmp(
                      peek(contestants[temp.contestant_number - 1]).state, 
                      "CROSS"
            ) != 0) {
                pop(&contestants[temp.contestant_number - 1]);
            }
        } else {
            push(&contestants[temp.contestant_number - 1], temp);
        }
    }
}

int print_in_file(FILE *pout, STACK *pstack) {
    LOG_ENTRY *ptemp;
    int step_count = 0;

    while((ptemp = pop(pstack)) != NULL) {
        fprintf(pout, "%u %s %s %s\n", ptemp->contestant_number,
                                       ptemp->first_name,
                                       ptemp->last_name,
                                       ptemp->state);
        step_count++;
    }

    fprintf(pout, "------------------------------");
    fprintf(pout, "\n%d", step_count);

    return step_count;
}


void init_array(DYN_ARRAY *pda) {
    pda->pa = NULL;
    pda->capacity = 0;
}

void resize_array(DYN_ARRAY *pda, int increase_factor) {
    pda->capacity += increase_factor;

    pda->pa = realloc(pda->pa, pda->capacity * sizeof(LOG_ENTRY));

    if(pda->pa == NULL) {
        puts("Out of memory. Program will now exit.");
        exit(EXIT_FAILURE);
    }
}

void destroy_array(DYN_ARRAY *pda) {
    free(pda->pa);
    init_array(pda);
}

void init_stack(STACK *pstack) {
    pstack->ptop = NULL;
    init_array(&pstack->host);
}

void resize_stack(STACK *pstack, int increase_factor) {
    int old_capacity = pstack->host.capacity;

    resize_array(&pstack->host, increase_factor);

    pstack->ptop = pstack->host.pa + old_capacity;
}

int is_full(STACK stack) {
    return stack.ptop == stack.host.pa + stack.host.capacity;
}

int is_empty(STACK stack) {
    return stack.ptop == stack.host.pa;
}

void push(STACK *pstack, LOG_ENTRY value) {
    if(is_full(*pstack)) {
        resize_stack(pstack, BASE_CAPACITY);
    }

    *(pstack->ptop) = value;
    pstack->ptop++;
}

LOG_ENTRY *pop(STACK *pstack) {
    LOG_ENTRY *ptop = NULL;

    if(!is_empty(*pstack)) {
        ptop = --pstack->ptop;
        LOG_ENTRY *plimit = (pstack->host.capacity + pstack->host.pa)
                            - BASE_CAPACITY;

        if(pstack->ptop < plimit) {
            resize_stack(pstack, -BASE_CAPACITY);
        }
    }

    return ptop;
}

LOG_ENTRY peek(STACK stack) {
    return *(stack.ptop - 1);
}

void destroy_stack(STACK *pstack) {
    destroy_array(&pstack->host);
    init_stack(pstack);
}

STACK reverse(STACK stack) {
    LOG_ENTRY *ptemp;
    STACK reversed_stack;

    init_stack(&reversed_stack);

    while((ptemp = pop(&stack)) != NULL) {
        push(&reversed_stack, *ptemp);
    }

    return reversed_stack;
}

