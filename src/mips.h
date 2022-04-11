#ifndef MIPS
#define MIPS

#include"parser.h"


/*
The mips architecture provides the MAL register
so for all the operaton.
MAL is a load/store architecture.


from: https://www.cs.uaf.edu/2000/fall/cs301/notes/notes/node65.html
In MAL:
There are no data types. The bits at a memory location have no inherent meaning and are not self-identifying.
Data are moved between RAM and register memory, located in the CPU, using separate load and store instructions.
All arithmetic, logical, and conditional branch instructions are performed on register operands only.
All instructions use a 32-bit word format. 


 RISC load/store architectures gain speed and performance by:

Separating memory access load/store operations from computational operations. This allows operands to be pre-loaded.
Requiring all computational operands to reside in CPU memory (registers) to avoid memory access delays.
Making all instructions as short as possible and using a fixed size. This allows instructions to be pre-loaded in blocks to minimize memory access delays in fetching the instructions. 

*/





typedef struct mips
{
        /*

    ### main register

    */

    int s0;
    int s1;
    int s2;
    int s3;
    int s4;
    int s5;
    int s6;
    int s7;
    int s8;


    /*

    ### sub program register

    */

    int t0;
    int t1;
    int t2;
    int t3;
    int t4;
    int t5;
    int t6;
    int t7;
    int t8;

    /*

    ### subprogram parametres

    */

    int a0;
    int a1;
    int a2;
    int a3;


    /*

    ### subprogram return values and syscall codes and return values

    */

    int v0;
    int v1;

}Mips;



static Mips mip = { .a0 = 0, 
                    .a1 = 0, 
                    .a2 = 0,
                    .s0 = 0,
                    .s1 = 0,
                    .s2 = 0,
                    .s3 = 0,
                    .s4 = 0,
                    .s5 = 0,
                    .s6 = 0,
                    .s7 = 0,
                    .s8 = 0,
                    .t0 = 0,
                    .t1 = 0,
                    .t2 = 0,
                    .t3 = 0,
                    .t4 = 0,
                    .t5 = 0,
                    .t6 = 0,
                    .t7 = 0,
                    .t8 = 0,
                    .a0 = 0,
                    .a1 = 0,
                    .a2 = 0,
                    .a3 = 0,
                    .v0 = 0,
                    .v1 = 0
                
                };




void set_value(const char *,int);

int pop_register(const char *);

void compile(Line [],size_t);

int is_label(const char *lab);




#endif