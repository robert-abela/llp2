all: hello
hello: main.o hello_fn.o
	gcc main.o hello_fn.o -o newhello
main.o: main.c
	gcc -Wall -c main.c
hello_fn.o: hello_fn.c
	gcc -Wall -c hello_fn.c
clean:
	-rm *.o newhello
