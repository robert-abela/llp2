#include <stdio.h>

int main(int argc, char *argv[]) {
    char* string = "Roger";
	char* marker = string;
	while (1) {
		printf("%c", *marker++);
	}
	
    return 0;  
}
