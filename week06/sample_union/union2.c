#include <stdio.h>
#include <string.h>
 
union my_union {
   int whole_num;
   float floating_point;
   char string[100];
};

int main(void) {
	union my_union my_data;        

	// Data corruption
	my_data.whole_num = 221;
	my_data.floating_point = 101.5;
	strcpy(my_data.string, "A string shorter than 100 chars");

	printf("my_data.whole_num : %d\n", my_data.whole_num);
	printf("my_data.floating_point : %f\n", my_data.floating_point);
	printf("my_data.string : %s\n", my_data.string);

	// Proper usage
	my_data.whole_num = 221;
	printf("my_data.whole_num : %d\n", my_data.whole_num);
	my_data.floating_point = 101.5;
	printf("my_data.floating_point : %f\n", my_data.floating_point);
	strcpy(my_data.string, "A string shorter than 100 chars");
	printf("my_data.string : %s\n", my_data.string);

	return 0;
}
