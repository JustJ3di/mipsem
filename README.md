# mipsem how run it ?

sh run.h "filename" for run it.

# Simulator
The software is a lightweight mips assembly simulator,
it can be considered as a simple interpreter of the latter.

 ## Parser
 The parser is very simple tokenize the <.s> file and isnerate all the tokens in an Istr structure
```c
struct line{
	
	char token[10][128];

	size_t total_token;

	size_t istr;
	
};
```
## Stack
For memory it is done with a simple stack structure.
```c
typedef struct label Map;

struct label
{

    int line_number;

    int size;

    Map *next;

    char label[];

};

```
The allocation of this structure is very simple every time the compile finds a new label, it saves it on the stack by allocating a new structure.
```c
Map *new = (Map *)malloc(sizeof(Map) + size_label + 1);
```