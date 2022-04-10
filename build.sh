gcc -g -c -o  hash.o hash.c  -Wall -Wextra
gcc -g -c -o  parser.o parser.c  -Wall -Wextra
gcc -g -c -o  compile.o compile.c  -Wall -Wextra
gcc -g -c -o  mips.o mips.c -Wall -Wextra

gcc -o test mips.o parser.o compile.o hash.o 