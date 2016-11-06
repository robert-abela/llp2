#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char* buffer = (char*)malloc(128);
	int number = 0;
	char c = 0;
	printf("Enter a word: ");
	scanf("%s", buffer);
	printf("Enter a number: ");
	scanf("%d", &number);
	c = buffer[number];
	printf("Character at %d = %c: \n", number, c);
	return 0;
}
