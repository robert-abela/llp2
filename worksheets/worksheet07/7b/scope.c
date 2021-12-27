#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* pointer_stack;
char* pointer_heap;

void init_pointers(void) {
	char local_array[100];
	pointer_stack = local_array;
	pointer_heap = malloc(100);

	strcpy(pointer_heap, "testString");
	strcpy(pointer_stack, "testString");
}

void print_pointers(void) {
	//char local_array[100] = {0};

	printf("pointer_heap:  %s\n", pointer_heap);
	printf("pointer_stack: %s\n", pointer_stack);
}

int main(void) {
	init_pointers();
	print_pointers();

	free(pointer_heap);
	return 0;
}