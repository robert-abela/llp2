#include <stdio.h>

int main(void)
{
	FILE *fp = fopen("file.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "Can't open input file!\n");
	}
	else {
		fprintf(stdout, "Successfully opened file!\n");
		fclose(fp);
	}
	
	return 0;
}
