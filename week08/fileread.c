#include <stdio.h>

int main(void) {
	char string[64];
	int  num;
	FILE *fp;

	fp = fopen("file.txt", "r");
	if (fp != NULL) {
		//file was opened
		while (!feof(fp)) {
			//there is still something left to read
			if (fscanf(fp, "%s %d", string, &num) != 2)
				break; //the file format is not as i expected
			printf("Read: %s\t%d\n", string, num);
		}

		fclose(fp);
	}
	
	return 0;
}
