gcc -g -c -o  hash.o src/stack.c  -Wall -Wextra
gcc -g -c -o  parser.o src/parser.c  -Wall -Wextra
gcc -g -c -o  compile.o src/compile.c  -Wall -Wextra
gcc -g -c -o  mips.o src/mips.c  -Wall -Wextra

gcc -o test mips.o parser.o compile.o hash.o 