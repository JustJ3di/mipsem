#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>

#include"parser.h"
#include"mips.h"
#include "hash.h"

#define INIT_SIZE 200

static Line * init_stack(Line *stack,int *n){

	stack = malloc(sizeof(Line)*INIT_SIZE);
	
	assert(stack!=NULL);

	for (int i = 0; i < *n+INIT_SIZE; i++)
	{
		stack[i].istr =0;
		stack[i].total_token = 0;
		for (size_t n = 0; n < 7; n++)
		{
			for (size_t j = 0; j < 128; j++)
			{
				stack[i].token[n][j] = 'x';	
			}
			
		}
		
	}
	return stack;

}




int main(int argc, char const *argv[]){


	FILE *file = fopen(argv[1],"r");
	

	assert(file!=NULL);

	
	size_t n = 256;
	char buff[256];
	int istr = 0;
	Line *stack = NULL;
	stack = init_stack(stack,&istr);
	

	
	Line *new_line = NULL;

	while(!feof(file)){

		char *b = fgets(buff,n,file);
		

		size_t size_len = strlen(b);
		new_line  = (Line *)init_line(b,istr,size_len);
		assert(new_line!=NULL);


		
		
		stack[istr] = *new_line;
		istr++;
		free(new_line);

	}

	

	compile(stack,istr+1);

	free(stack);


#if DEBUG
	print();
#endif

	destroy_table();

	fclose(file);

	return 0;

}