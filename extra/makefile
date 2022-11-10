default: clean build
clean: 
	-rm variables datatypes pointers arrays hundred_bytes
build:
	gcc -Wall -Wno-uninitialized variables.c -o variables
	gcc -Wall -Wno-overflow datatypes.c -o datatypes
	gcc -Wall pointers.c -o pointers
	gcc -Wall arrays.c -o arrays
	gcc -Wall hundred_bytes.c -o hundred_bytes