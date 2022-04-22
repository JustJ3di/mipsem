#ifndef MIPS
#define MIPS

#include"parser.h"


#define REGISTER 0

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

//#########################################################################################################################################

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


enum sys_call{

    PRINT_INT = 1,
    PRINT_STRING = 4,
    READ_INT = 5,
    READ_STRING = 8,
    SBRK  = 9,
    EXIT = 10,
    PRINT_CHAR = 11,
    READ_CHAR = 12
    
};







int system_call();


void set_value(const char *,int);

int pop_register(const char *);

void compile(Line [],size_t);

int is_label(const char *lab);




#endif