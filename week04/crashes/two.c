#include <stdio.h>

int main(int argc, char *argv[]) {
    int *ptr = NULL;  
    printf("Address: %p", ptr);
    printf("Value: %d", *ptr);
    return 0;  
}
