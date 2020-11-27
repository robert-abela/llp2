#include <stdio.h>
#include <stdlib.h>
#define ARR_SIZE    10
int main(int argc, char **argv){

    int arr_stack[ARR_SIZE] = {0};
    int *arr_heap = (int*)malloc(sizeof(int)*ARR_SIZE);
    if (arr_heap == NULL) {
        printf("Out of memory\n");
        return -1;
    }
    
    *arr_stack = 100;
    *(arr_stack+1) = 101;
    arr_stack[2] = 103;
    arr_stack[3] = 104;
    
    for (int i = 0; i < ARR_SIZE; i++) {
        *(arr_heap+i) = 100+i;
    }

    free(arr_heap);
    return 0;
}
