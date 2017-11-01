#include <stdio.h> 
long global; /* Uninitialized variable stored in BSS */ 
int main(void) 
{
    /* Initialized static variable stored in Data segment */
    static long i = 100;
    return 0; 
}
