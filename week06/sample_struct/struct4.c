#include <stdio.h> 
#include <stdbool.h>

struct int_car_struct {
    int has_ac;
    int is_manual;
    int has_tinted;
};

struct packed_car_int_struct {
    int has_ac:1;
    int is_manual:1;
    int has_tinted:1;
};

struct bool_car_struct {
    bool has_ac;
    bool is_manual;
    bool has_tinted;
};

struct packed_car_bool_struct {
    bool has_ac:1;
    bool is_manual:1;
    bool has_tinted:1;
};

int main(void) {
	struct int_car_struct i_car1;
	struct packed_car_int_struct i_packed_car1;
	struct bool_car_struct b_car1;
	struct packed_car_bool_struct b_packed_car1;

	printf("size of int_car_struct:    %ld\n", sizeof(i_car1));
	printf("size of char_car_int_struct:   %ld\n", sizeof(i_packed_car1));
	printf("size of bool_car_struct:   %ld\n", sizeof(b_car1));
	printf("size of packed_car_bool_struct: %ld\n", sizeof(b_packed_car1));
    
    return 0; 
} 
