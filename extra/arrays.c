#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

    char array_init[] = "abcd";
    printf("%c",   array_init[0]);
    printf("%c",   array_init[1]);
    printf("%c",   array_init[2]);
    printf("%c\n", array_init[3]);
    
    char array_uninit[5];
    char* test = array_uninit;
    strcpy(test, "bye");
    printf("%c\n", array_uninit[0]);
    printf("%c", *test);
    printf("%c", *(test+1));
    printf("%c\n", *(test+2));

    char* array_heap = malloc(sizeof(char) * 5);
    printf("%c\n", array_heap[0]);
    free(array_heap);
    return 0;
}
