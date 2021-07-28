#include <stdio.h>
#include "datatypes.h"

int main() {
    char one_byte = 0;
    short two_bytes = 0; //int (on old systems)
    int four_bytes = 0; //float
    double eight_bytes = 0; //long

    printf("Size of char: %zu byte\n", sizeof(one_byte));
    printf("Size of short: %zu bytes\n", sizeof(two_bytes));
    printf("Size of int: %zu bytes\n", sizeof(four_bytes));
    printf("Size of double: %zu bytes\n", sizeof(eight_bytes));

    one_byte = 65;
    printf("char using %%c %c\n", one_byte);
    printf("char using %%d %d\n", one_byte);

    //putting smaller values in larger spaces -> no warning
    eight_bytes = four_bytes = two_bytes = one_byte;

    one_byte = 555222; //overflow warning
    printf("char using %%d %d\n", one_byte);

    four_bytes = 555222;
    one_byte = four_bytes; //no warning!

    one_byte    =        55; //max 128
    two_bytes   =      5555; //max 32,767
    four_bytes  =   5555555; //max 2,147,483,647
    eight_bytes = 555555555; //max very large!

    printf("original %d\n", one_byte);
    printf("original %d\n", two_bytes);
    printf("original %d\n", four_bytes);
    printf("original %.0lf\n", eight_bytes);

    my_function(one_byte);
    my_function(two_bytes); //no warning!
    my_function(four_bytes); //no warning!
    my_function(eight_bytes); //no warning!

    return 0;
}