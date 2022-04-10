#ifndef PARSE
#define PARSE
#include<stdio.h>
#include <assert.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define DEBUG 1


typedef struct line Line;

struct line{
	
	char token[10][128];

	size_t total_token;

	size_t istr;


};

//Build the object
void *init_line(const char *,int,size_t);





#endif
