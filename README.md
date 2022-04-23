# mipsem how run it ?

sh run.h <filename> for run it.

# Simulator
The software is a lightweight mips assembly simulator,
it can be considered as a simple interpreter of the latter.

 # Parser
 The parser is very simple tokenize the <.s> file and isnerate all the tokens in an Istr structure
```c
  struct line{
	
	char token[10][128];

	size_t total_token;

	size_t istr;


};
```
