#include <stdio.h>

int main(void)
{
	char string[64];
	int  num;
	FILE *fp;

	fp = fopen("file.txt", "r");
	if (fp != NULL)
	{
		while (!feof(fp)) {
			if (fscanf(fp, "%s %d", string, &num) != 2)
				break;
			printf("Read: %s\t%d\n", string, num);
		}

		fclose(fp);
	}
}
