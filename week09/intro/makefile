all: check_posix thread_example thread_params_example thread_return

rebuild: clean all

check_posix:
	gcc -Wall -o check_posix check_posix.c

thread_example:
	gcc -Wall -o thread_example thread_example.c -lpthread

thread_params_example:
	gcc -Wall -o thread_params_example thread_params_example.c -lpthread

thread_return:
	gcc -Wall -o thread_return thread_return.c -lpthread

clean:
	-rm check_posix thread_example thread_params_example thread_return