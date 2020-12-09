#include <stdio.h>
#include <string.h>

#define TRUE  1
#define FALSE 0

int main(void)
{
	char buffer[11];
	int correct_password = FALSE;
	
	printf("Enter password: ");
	gets(buffer);
	
    if (strncmp(buffer, "letmein", 7) == 0)
		correct_password = TRUE;
	else
		printf ("Incorrect Password!\n");
	
	if (correct_password != FALSE)
		printf ("Performing tasks that require password...\n");

	return 0;
}
