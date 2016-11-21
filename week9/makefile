all: check_posix  thread_example thread_params_example balance_mutex_example 

check_posix:
	gcc -Wall -o intro/check_posix intro/check_posix.c

thread_example:
	gcc -Wall -lpthread -o intro/thread_example intro/thread_example.c

thread_params_example:
	gcc -Wall -lpthread -o intro/thread_params_example intro/thread_params_example.c

balance_mutex_example:
	gcc -Wall -lpthread -o sync/balance_mutex_example sync/balance_mutex_example.c

clean:
	-rm intro/check_posix intro/thread_example intro/thread_params_example sync/balance_mutex_example