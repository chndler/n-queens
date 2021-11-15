all: single-thread multi-thread

single-thread: singlethread.c nqueens_library.c
	gcc -o single-thread singlethread.c nqueens_library.c

multi-thread: multithread.c nqueens_library.c
	gcc -o multi-thread multithread.c nqueens_library.c -lm

clean:
	rm -f single-thread *.o
	rm -f multi-thread *.o


