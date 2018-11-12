#include <stdio.h>

int main(void)
{
	FILE *fp = fopen("file.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "Can't open input file in.list!\n");
	}
	else {
		fprintf(stdout, "Successfully opened file!\n");
		fclose(fp);
	}
}
