#include <stdio.h>

int main(int argc, char *argv[]) {
	char strings[3][10] = {"one","two","three"};
	int number;

	printf("Enter a number: ");
	scanf("%d", &number);
	printf("strings[%i] = %s\n", number, strings[number]);
	return 0;
}

