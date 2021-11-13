#include <stdlib.h>

int main (void) {
    void *pointers[9];
    pointers[0] = malloc(1024); // this allocation not freed!

    for (int i = 1; i < 9; i++) // alloc 8 buffers
        pointers[i] = malloc(128);

    for (int i = 1; i < 9; i++) 
        free(pointers[i]); // free 8 buffers
    
    return 0;
}
