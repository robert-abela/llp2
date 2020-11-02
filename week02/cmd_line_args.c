#include <stdio.h>

int main( int argc, char *argv[] )  {

	printf("Program name %s\n", argv[0]);

	if( argc == 1 ) {
		printf("No arguments supplied\n");
	}
	else {
		for (int i = 1; i < argc; i++) {
	    	printf("argc[%d] = %s\n", i, argv[i]);
		}
	}
}
