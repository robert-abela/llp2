/**
  Write a C program (plus makefile for it) that does the following:
   - declare an int on the stack, do not assign any value
   - declare an int as global, do not assign any value
   - print the value of both integers - what is the difference?
   - Create 3 strings (of 100 bytes each) one on the stack, one heap and one global
   - Write your name in each of the strings
   - Create a new char pointer on the stack, do not assign any value to it
   - Print the value of this last pointer (its address not the content of at the address)
   - Make the last pointer point to the 3 strings, printing the string contents (your name) each time
   - Free any memory that you allocated
   - return 0
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int global_int;
char global_string[100];

int main(void) {
    int stack_int;
    printf("stack_int:  %d\n", stack_int); //warning: ‘stack_int’ is used uninitialized
    printf("global_int: %d\n\n", global_int); //no warning

    char *heap_string = malloc(100);
    char stack_array[100];
    char *stack_string;

    strncpy(heap_string, "I am in the  Heap", 100);
    strncpy(stack_array, "I am on the Stack", 100);
    strncpy(global_string, "I am a Global", 100);

    printf("global int:    %p\n", &global_int);
    printf("global string: %p\n", &global_string);
    printf("-----------------------------\n");
    printf("heap string:   %p\n", heap_string);
    printf("-----------------------------\n");
    printf("stack int:     %p\n", &stack_int);
    printf("stack string:  %p\n", &stack_string);
    printf("stack array:   %p\n\n", &stack_array);
    
    stack_string = heap_string;
    printf("stack_string pointing to the heap:  %s\n", stack_string);
    stack_string = stack_array;
    printf("stack_string pointing to the stack: %s\n", stack_string);
    stack_string = global_string;
    printf("stack_string pointing to global:    %s\n", stack_string);

    free(heap_string);
    return 0;
}
