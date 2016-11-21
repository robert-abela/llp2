all: check_posix  thread_example thread_params_example  

check_posix:
	gcc -Wall -o check_posix check_posix.c

thread_example:
	gcc -Wall -lpthread -o thread_example thread_example.c

thread_params_example:
	gcc -Wall -lpthread -o thread_params_example thread_params_example.c

clean:
	-rm check_posix thread_example thread_params_example