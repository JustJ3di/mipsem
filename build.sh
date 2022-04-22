
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