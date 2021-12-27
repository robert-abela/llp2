#include <stdio.h>
 
union my_union {
   int whole_num;
   float floating_point;
   char string[100];
};

int main(void) {
   union my_union my_data;        
   printf("size of my_data : %ld\n", sizeof(my_data));
   return 0;
}
