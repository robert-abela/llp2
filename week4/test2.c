#include <stdio.h>
#include <stdlib.h>

char c;

void do_user_input()
{
	char* buffer = (char*)malloc(128);
	int number = 0;

	printf("Enter a word: ");
	scanf("%s", buffer);
	printf("Enter a number: ");
	scanf("%d", &number);
	c = buffer[number];
	printf("Character at %d = %c: \n", number, c);
	free(buffer);
}

int main(int argc, char **argv)
{
	do_user_input();
	return 0;
}
