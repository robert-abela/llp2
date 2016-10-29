#include <stdio.h>
#include <stdbool.h>
#include "stack_array.h"

int main(int argc, char *argv[]) 
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    printf("Stack elements: \n");
    while (!is_empty())
        printf("%d\n", pop());

    if (is_empty())
        printf("Stack empty!\n");
    return 0;
}
