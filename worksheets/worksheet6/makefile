all: default_stack large_stack

default_stack:
	gcc -Wall -o default stack_test.c
large_stack:
	gcc -Wall -Wl,--stack,10240000 -o large stack_test.c
clean:
	rm default large