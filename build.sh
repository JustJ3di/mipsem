
#Copyright (c) <2022> <Emanuele d'Ajello>

#Permission is hereby granted, free of charge, to any person obtaining a copy
#of this software and associated documentation files (the "Software"), to deal
#in the Software without restriction, including without limitation the rights
#to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#copies of the Software, and to permit persons to whom the Software is
#furnished to do so, subject to the following conditions:

#The above copyright notice and this permission notice shall be included in all
#copies or substantial portions of the Software.

#THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#SOFTWARE.


CC=gcc
FLAGS="-Wall -Wextra"

for arg in "$@"
do
	case $arg in
		   --debug) FLAGS="$FLAGS -DDEBUG -g" 
			  	    ;;
		 --release) FLAGS="$FLAGS -DNDEBUG -O3" 
			  	    ;;

		--valgrind) FLAGS="$FLAGS -DUSING_VALGRIND=1"
					;;

		--coverage) CC=clang
					FLAGS="$FLAGS -fprofile-instr-generate -fcoverage-mapping"
					;;

		 --fuzzing) CC=afl-clang-fast
					;;
	esac
done



gcc -g -c -o  hash.o src/stack.c $FLAGS
gcc -g -c -o  parser.o src/parser.c  $FLAGS
gcc -g -c -o  compile.o src/compile.c  $FLAGS
gcc -g -c -o  mips.o src/mips.c  $FLAGS

gcc -o test mips.o parser.o compile.o hash.o $FLAGS