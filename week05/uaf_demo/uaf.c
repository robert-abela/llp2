/*
 * Referencing memory after it has been freed can cause a program to crash, use unexpected values, or execute code. 
 * It is always good practice to set pointers to NULL after freeing them.
 * https://cwe.mitre.org/data/definitions/416.html
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ONE_KB	1024
#define BUFF_SIZE 128 * ONE_KB	

int main()
{
	char *buffer1 = (char*)malloc(BUFF_SIZE);
	strcpy(buffer1, "Hello");
	free(buffer1);

	char *buffer2 = (char*)malloc(BUFF_SIZE);

	printf("buffer1 = %p\n", buffer1);
	printf("buffer2 = %p\n", buffer2);
	
	strcpy(buffer1, "bye");
	free(buffer2);

	return 0;
}
