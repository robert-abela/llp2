#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/** Updates the 2 values, returns true */
//bool update_values(int width, int height) {
bool update_values(int *width, int *height) {
	//width = 10;
	*width = 10;
	//height = 19;
	*height = 19;
	return true;
}

int main(){
    int width = 0, height = 0;
    //bool ok = update_values(width, height);
	bool ok = update_values(&width, &height);
	if (ok)
		printf("%d:%d\n", width, height);

    return 0;
}
