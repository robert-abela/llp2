#include <stdio.h>

int main(void) {
	char *string = "this is just a chunk of characters.";
	FILE *fp;

	fp = fopen("out.txt", "w");
	if (fp != NULL) {
		fprintf(fp, "%s\n", string);
		fclose(fp);
	}
	
	return 0;
}
