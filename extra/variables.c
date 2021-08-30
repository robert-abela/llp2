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
char string_global[100];

int main(void) {
    int stack_int;
    printf("stack_int:  %d\n", stack_int);
    printf("global_int: %d\n", global_int);
    //printf("global_int:  %p\n", &global_int);
    //printf("stack_int:  %p\n", &stack_int);

    char *string_heap = malloc(100);
    char string_stack[100];
    //printf("string_heap:  %p\n", string_heap);
    //printf("string_stack:  %p\n", &string_stack);
    //printf("string_global:  %p\n", &string_global);
    strncpy(string_heap, "Robert Heap", 100);
    strncpy(string_stack, "Robert Stack", 100);
    strncpy(string_global, "Robert Global", 100);

    char *stack_new;
    printf("stack_new:  %p\n", &stack_new);
    
    stack_new = string_heap;
    printf("string_heap->stack_new:  %s\n", stack_new);
    stack_new = string_stack;
    printf("string_stack->stack_new:  %s\n", stack_new);
    stack_new = string_global;
    printf("string_global->stack_new:  %s\n", stack_new);

    free(string_heap);
    return 0;
}