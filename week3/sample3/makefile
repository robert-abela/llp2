# CC represents the compiler the compiler to use
CC=gcc
# CFLAGS are the compiler options
CFLAGS=-Wall -c
# executable file names
WIN_OUT=hello_win
LNX_OUT=hello_lnx

all: hello_win hello_lnx

hello_win: main_win.o
	$(CC) main.o -o $(WIN_OUT)
hello_lnx: main_lnx.o
	$(CC) main.o -o $(LNX_OUT)

main_win.o: main.c
	$(CC) $(CFLAGS) -DWIN32 main.c
main_lnx.o: main.c
	$(CC) $(CFLAGS) -DLINUX main.c

clean:
	rm *.o $(WIN_OUT) $(LNX_OUT)
