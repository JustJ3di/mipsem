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

static Map *head = NULL;

void push_new_label(const char *label,int line){


    

    int size_label = strlen(label);
    
    Map *new = (Map *)malloc(sizeof(Map) + size_label + 1);

    assert(new != NULL);

    new->line_number = line;

    new->size = size_label;
    
    new->next = head;

    head = new;

    
    for (int i = 0; i < size_label + 1; i++)
    {
       
        new->label[i] = label[i];
        
    }
    
#ifdef DEBUG
    printf("label : (%s) saved at line %d\n",new->label,new->line_number);
#endif

    

}

void print(){

    Map *current = head;


    while (current != NULL)
    {
        
        printf("%s\n",current->label);

        current = current->next;

    }
    

}

void destroy_table(){

    Map *current = head;
    Map *tmp;

    while (current != NULL)
    {
    
        tmp = current->next;

        free(current);        

        current = tmp;

    }


}


int pop_istruction_number_from_label(const char *label){


    Map *current = head;


    while (current != NULL)
    {
        
        if (strcmp(current->label,label) == 0)
        {
        
            return current->line_number;
        
        }
        
        current = current->next;

    }
    

    return -1;


}
