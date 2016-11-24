#include <stdio.h>
#include <string.h>

int main(void)
{
	char buffer[11];
	int correct_password = 0;
	
	printf("Enter password: ");
	gets(buffer);
	
	if (strcmp(buffer, "letmein"))
		printf ("Incorrect Password!\n");
	else
		correct_password = 1;
	
	if (correct_password != 0)
		printf ("Performing tasks that require password...\n");

	return 0;
}