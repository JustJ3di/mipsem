#ifndef HASH
#define HASH
#include"mips.h"

typedef struct hash_label Map;

struct hash_label
{

    int line_number;

    int size;

    Map *next;

    char label[];

};


static Map *head = NULL;

void push_new_label(const char *label,int line);

void print();

int pop_istruction_number_from_label(const char *label);

void destroy_table();


#endif