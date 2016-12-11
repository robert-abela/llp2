all: clean counter counter_mutex

counter:
	gcc -Wall -o counter counter.c -lpthread

counter_mutex:
	gcc -Wall -o counter_mutex counter_mutex.c -lpthread

clean:
	-rm counter counter_mutex