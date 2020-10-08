all: clean threads

threads: clean
	gcc -Wall -lpthread -o threads main.c thread.c

clean:
	-rm threads