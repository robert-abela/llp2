#include <stdio.h>

void recurse(int param) {
	int numbers[10240] = {10};
	recurse(param+numbers[0]);
}

int main(int argc, char *argv[]) {
	recurse(100);
	return 0;
}

