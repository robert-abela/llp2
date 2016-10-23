all: check_posix  thread_example balance_mutex_example

check_posix:
	gcc -Wall -o check_posix check_posix.c

thread_example:
	gcc -Wall -lpthread -o thread_example thread_example.c

balance_mutex_example:
	gcc -Wall -lpthread -o balance_mutex_example balance_mutex_example.c

clean:
	-rm check_posix thread_example balance_mutex_example