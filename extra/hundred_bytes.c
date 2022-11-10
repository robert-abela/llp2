/*
  - Create a buffer of 50 bytes on the heap
  - Write your name at index zero of the buffer
  - Write your surname at index 25
  - Can you think of other ways of achieving this outcome?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFSIZE 50

void print_chars(char* buffer, unsigned short size) {
    for (unsigned short i = 0; i < size; i++)
        printf("buffer[%d] %hu -> %c\n", i, buffer[i], buffer[i]);
}

struct FullName {
    char name[25];
    char surname[25];
};

int main(void) {
    //Option 1
    char *buffer = malloc(BUFFSIZE);
    if (buffer == NULL)
        return -1;

    char *name = buffer, *surname = buffer + 50;
    strcpy(name, "Kathleen");
    strcpy(surname, "Booth");
    print_chars(buffer, BUFFSIZE);
    free(buffer);

    //Option 2
    struct FullName *structure = malloc(sizeof(struct FullName));
    strcpy(structure->name, "Kathleen");
    strcpy(structure->surname, "Booth");
    print_chars((char*)structure, BUFFSIZE);
    free(structure);
    return 0;
}

// Kathleen Booth (9 July 1922 – 29 September 2022) was a British computer 
//  scientist and mathematician who wrote the first assembly language and 
//  designed the assembler and autocode for the first computer systems at
//  Birkbeck College, University of London.
//  https://en.wikipedia.org/wiki/Kathleen_Booth