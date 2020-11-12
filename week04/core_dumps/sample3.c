#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	char strings[3][10] = {"one","two","three"};
    int index = atoi(argv[1]);
   	printf("strings[%i] = %s\n", index, strings[index]);
    return(0);
}
