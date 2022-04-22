#include  "parser.h"


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


/*
the purpose of this code is to divide by token the instructions read from the file, 
excluding all special characters such as commas, spaces, tabs, newlines and endlines.
*/


void *init_line(const char *string , int numb_istr,size_t size_line){

	Line  *new = (Line *)malloc(sizeof(Line));

	assert(new != NULL);

	new->istr = numb_istr;

	int i = 0; //byte line
	char tokenize[128] ;
	for (size_t i = 0; i < 128; i++)
	{
		tokenize[i] = 'x';
	}
	

	int j = 0; //byte token
	int t = 0; //number token
	


	while(i<(int)size_line+1){


		switch (string[i])
		{
		case '\t':
		case '\0':
		case '\n':
		case ',':
		case ':':
		case ' ':

			
			if(j!=0){
				tokenize[j]= '\0';
				strcpy(new->token[t],tokenize);
				new->total_token++;
				t++;
				j = 0;
#ifdef DEBUG
				printf("(%s)\n",tokenize);
#endif
			}
			
			i++;
			break;

		case '"':
			do
			{	
				tokenize[j] = string[i];
				i++;
				j++;
			} while (string[i]!='"');
			tokenize[j] = string[i];
			j++;

			tokenize[j+1] = '\0';// he take this token in the next iteration beacuse he got the '\0' case!
			i++;
			
			break;

		default:
			tokenize[j] = string[i];
			j++;
			i++;
			break;
		}
	}
	
	return (void *)new;

}
