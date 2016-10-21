#include <stdio.h>

int main(void)
{
	FILE ifp = fopen("file.txt", "r");
	if (ifp == NULL) 
		fprintf(stderr, "Can't open input file in.list!\n");
	else 
		fprintf(stdout, "Successfully opened file!\n");

	fclose(ifp);
}
