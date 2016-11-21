all: counter  counter_mutex

counter:
	gcc -Wall -lpthread -o counter counter.c

counter_mutex:
	gcc -Wall -lpthread -o counter_mutex counter_mutex.c

clean:
	-rm counter counter_mutex