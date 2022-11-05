#include <stdio.h>
#include <stdlib.h>

int g = 0;   /* a global variable, stored in BSS segment */

int main(int argc, char **argv) {
    static int s;  /* static local variable, stored in BSS segment */
    int a;         /* automatic variable, stored on stack */
    int *p;        /* pointer variable for malloc below */

    /* obtain a block big enough for one int from the heap */
    p = malloc(sizeof(int));

    printf("global   = %p\n", (void *) &g);
    printf("static   = %p\n", (void *) &s);
    printf("stack_a  = %p\n", (void *) &a);
    printf("stack_p  = %p\n", (void *) &p);
    printf("heap     = %p\n", (void *) p);
    printf("txt/code = %p\n", (void *) main);

    free(p);
    return 0;
}
