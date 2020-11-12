#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	char strings[3][10] = {"one","two","three"};
    int random;
    time_t t;
   
    /* Intializes random number generator */
    srand((unsigned) time(&t));

    /* generate a random number from 0 to 9999 */
    random = rand() % 10000;
   	printf("strings[%i] = %s\n", random, strings[random]);
    return(0);
}
