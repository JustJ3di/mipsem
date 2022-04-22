#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>

#include"parser.h"
#include"mips.h"
#include "stack.h"


/*
Copyright (c) <2022> <Emanuele d'Ajello>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


#define INIT_SIZE 1000

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

	if (argc<2)
	{
		fprintf(stderr,"error\n");
	}
	

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

	

	compile(stack,istr);


	free(stack);



#ifdef DEBUG
	print();
#endif

	destroy_table();

	fclose(file);

	return 0;

}