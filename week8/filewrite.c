#include <stdio.h>

int main(void)
{
	char *string = "this is just a chunk of characters.";
	FILE *fp;

	fp = fopen("out.txt", "w");
	fprintf(fp, "%s\n", string);
	fclose(fp);
}
