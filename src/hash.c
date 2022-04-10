#include "hash.h"



int push_new_label(const char *label,int line){

    if (pop_istruction_number_from_label(label)!=-1)
    {
        return -1;
    }
    

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
    
#if DEBUG
    printf("label : (%s) saved at line %d\n",new->label,new->line_number);
#endif

    return 1;

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
