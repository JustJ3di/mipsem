#include"mips.h"
#include"parser.h"
#include "hash.h"

#if DEBUG
    #include<unistd.h>
#endif


void set_value(const char *reg,int value){


    switch (reg[1])
    {
        case 'a':

            switch (reg[2])
            {
                case '0':
                    mip.a0 = value;
                    break;
                case '1':
                    mip.a1 = value;
                    break;
                case '2':
                    mip.a2 = value;
                    break;
                case '3':
                    mip.a3 = value;
                    break;
                }
            break;
        
        case 't':
        
            switch (reg[2])
            {
                case '0':
                    mip.t0 = value;
                    break;
                case '1':
                    mip.t1 = value;
                    break;
                case '2':
                    mip.t2 = value;
                    break;
                case '3':
                    mip.t3 = value;
                    break;
                case '4':
                    mip.t4 = value;
                    break;
                case '5':
                    mip.t5 = value;
                    break;
                case '6':
                    mip.t6 = value;
                    break;
                case '7':
                    mip.t7 = value;
                    break;
                case '8':
                    mip.t8 = value;
                    break;
            }

            break;
    
        case 'v':

            switch (reg[2])
            {
                case '0':
                    mip.v0 = value;
                    break;
                case '1':
                    mip.v1 = value;
                    break;
            }

            break;

        case 's':
            switch (reg[2])
        
            {
                case '0':
                    mip.s0 = value;
                    break;
                case '1':
                    mip.s1 = value;
                    break;
                case '2':
                    mip.s2 = value;
                    break;
                case '3':
                    mip.s3 = value;
                    break;
                case '4':
                    mip.s4 = value;
                    break;
                case '5':
                    mip.s5 = value;
                    break;
                case '6':
                    mip.s6 = value;
                    break;
                case '7':
                    mip.s7 = value;
                    break;
                case '8':
                    mip.s8 = value;
                    break;
                
            }


        break;

     
    default:
        break;
    }

}

int pop_register(const char *reg){



    
    switch (reg[1])
    {
        case 'a':

            switch (reg[2])
            {
                case '0':
                    return mip.a0 ;
                case '1':
                    return mip.a1 ;
                case '2':
                    return mip.a2;
                case '3':
                    return mip.a3;
                    
                }
            break;
        
        case 't':
        
            switch (reg[2])
            {
                case '0':
                    return mip.t0;
                    break;
                case '1':
                    return mip.t1 ;

                case '2':
                    return mip.t2 ;
                    
                case '3':
                    return mip.t3;
                    
                case '4':
                    return mip.t4 ;
                
                case '5':
                    return mip.t5 ;
                    
                case '6':
                    return mip.t6 ;
                    
                case '7':
                    return mip.t7 ;
                    
                case '8':
                    return mip.t8 ;
                    
            }

            break;
    
        case 'v':

            switch (reg[2])
            {
                case '0':
                    return mip.v0;
                    
                case '1':
                    mip.v1 ;
                    
            }

            break;

        case 's':
            switch (reg[2])
        
            {
                case '0':
                    return mip.s0 ;
                    
                case '1':
                    return mip.s1 ;
                    
                case '2':
                    return mip.s2 ;
                    break;
                case '3':
                    return mip.s3 ;
                    break;
                case '4':
                    return  mip.s4 ;
                    
                case '5':
                    return mip.s5 ;
                    
                case '6':
                    return mip.s6;
        
                case '7':
                    return mip.s7;
                    
                case '8':
                    return mip.s8;
                    
                
            }


        break;

     
    }

}

/*
https://www.d.umn.edu/~gshute/mips/mal-introduction.html
Instruction 	Operation
lw 	Rd, addr 	load integer (word)
sw 	Rs, addr 	store integer (word)
move 	Rd, Rs 	move integer
la 	Rd, label 	load address
li 	Rd, const 	load immediate


*/


int is_label(const char *lab){

    char *key[] = {"add","addi","sub","mul","move","li","beq","b"};
    
    for (size_t i = 0; i < 8; i++)
    {
        
        if (strcmp(lab,key[i]) == 0)
        {
        
            return 1;
        
        }
        
    }
    
    return -1;
    
}


void  compile(Line ist[],size_t n_istr){

    int istr = 0;
    while (istr < n_istr - 1)
    {


        #if DEBUG
            printf("istr n %d\n",istr);
        #endif

        if (strcmp(ist[istr].token[0],"li")==0)
        {
            set_value(ist[istr].token[1],atoi(ist[istr].token[2]));
            istr++;
        }
        else if(strcmp(ist[istr].token[0],"add")==0)
        {

            set_value(ist[istr].token[1],pop_register(ist[istr].token[2])+pop_register(ist[istr].token[3]));
            istr++;        

        }else if(strcmp(ist[istr].token[0],"mul")==0){

            set_value(ist[istr].token[1],pop_register(ist[istr].token[2])*pop_register(ist[istr].token[3]));
            istr++;        

        }else if(strcmp(ist[istr].token[0],"sub")==0){

            set_value(ist[istr].token[1],pop_register(ist[istr].token[2])-pop_register(ist[istr].token[3]));
            istr++;       

        }else if (strcmp(ist[istr].token[0],"div")==0){

            if(pop_register(ist[istr].token[3])==0)
                perror("divisore 0\n");
            
            set_value(ist[istr].token[1],pop_register(ist[istr].token[2])/pop_register(ist[istr].token[3]));
            istr++;   

        }else if (strcmp(ist[istr].token[0],"rem")==0)
        {

            if(pop_register(ist[istr].token[3])==0)
                perror("divisore 0\n");
            
            set_value(ist[istr].token[1],pop_register(ist[istr].token[2])%pop_register(ist[istr].token[3]));
            istr++;   

        }else if(strcmp(ist[istr].token[0],"move")==0){

            set_value(ist[istr].token[1],pop_register(ist[istr].token[2]));
            istr++;
        
        }else if (strcmp(ist[istr].token[0],"addi")==0){

            set_value(ist[istr].token[1],pop_register(ist[istr].token[2])+atoi(ist[istr].token[3]));      
            istr++;

        }else if (strcmp(ist[istr].token[0],"beq") == 0)
        {
 
            if (pop_register(ist[istr].token[1]) == pop_register(ist[istr].token[2])){

                int check = pop_istruction_number_from_label(ist[istr].token[1]);   
                int is = istr;
                #if DEBUG
                printf("check = %d",check);
                #endif
                if (check == -1)
                {

                    do
                    {
                        
                        istr++;

                        if(is_label(ist[istr].token[0]) != 1){
                            if(pop_istruction_number_from_label(ist[istr].token[0])<0)
                                push_new_label(ist[istr].token[0],istr);  
                        }

                    } while ( strcmp(ist[istr].token[0],ist[is].token[3]) != 0);

                    istr++; 
                
                }else
                    istr = check ;
                }
            istr++;

        }else if (strcmp("b",ist[istr].token[0])==0)
        {
            
            int check = pop_istruction_number_from_label(ist[istr].token[1]);   
            int is = istr;
            #if DEBUG
            printf("check = %d",check);
            #endif
            if (check == -1)
            {

                do
                {
                    
                    istr++;

                    if(is_label(ist[istr].token[0]) != 1){
                        if(pop_istruction_number_from_label(ist[istr].token[0])<0)
                            push_new_label(ist[istr].token[0],istr);  
                    }

                    

                } while ( strcmp(ist[istr].token[0],ist[is].token[1]) != 0);

                istr++; 
               
            }else
                istr = check ;
              
        }else{

            if(pop_istruction_number_from_label(ist[istr].token[0])<0)
                push_new_label(ist[istr].token[0],istr);  
            
            istr++;
              
        }
        

   

    }
    

    printf("s0 = %d\n",mip.s0);
    printf("s1 = %d\n",mip.s1);
    printf("s2 = %d\n",mip.s2);
    printf("s3 = %d\n",mip.s3);
    printf("s4 = %d\n",mip.s4);
    printf("s5 = %d\n",mip.s5);
    printf("s5 = %d\n",mip.s6);
    printf("s6 = %d\n",mip.s7);
    printf("s7 = %d\n",mip.s8);

}