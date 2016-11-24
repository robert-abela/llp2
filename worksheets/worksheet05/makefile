all: clean build

build: s1 s2 s3 s4 s5

s1:
	gcc -Wall -o test1 size1.c
s2:
	gcc -Wall -o test2 size2.c
s3:
	gcc -Wall -Wno-unused-variable -o test3 size3.c
s4:
	gcc -Wall -Wno-unused-variable -o test4 size4.c
s5:
	gcc -Wall -Wno-unused-variable -o test5 size5.c
clean:
	-rm test1 test2 test3 test4 test5

size:
	size test1
	size test2
	size test3
	size test4
	size test5