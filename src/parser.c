#include  "parser.h"





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
	


	while(i<size_line+1){


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
#if DEBUG
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
