#include <stdio.h> 
#include <stdbool.h>

struct int_car_struct {
    int has_ac;
    int is_manual;
    int has_tinted;
};

struct bool_car_struct {
    bool has_ac;
    bool is_manual;
    bool has_tinted;
};

struct char_car_struct {
    char has_ac;
    char is_manual;
    char has_tinted;
};

struct packed_car_struct {
    char has_ac:1;
    char is_manual:1;
    char has_tinted:1;
};

int main() 
{
	struct int_car_struct i_car1;
	struct bool_car_struct b_car1;
	struct char_car_struct c_car1;
	struct packed_car_struct p_car1;

	printf("size of int_car_struct:    %ld\n", sizeof(i_car1));
	printf("size of bool_car_struct:   %ld\n", sizeof(b_car1));
	printf("size of char_car_struct:   %ld\n", sizeof(c_car1));
	printf("size of packed_car_struct: %ld\n", sizeof(p_car1));
    
    return 0; 
} 
