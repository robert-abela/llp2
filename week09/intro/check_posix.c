#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv) {
	printf("Sample Program...\n");
#ifdef _POSIX_THREADS
	printf("This program was compiled with thread support.\n");
#else
	printf("This program was compiled without thread support.\n");
#endif

	return 0;
}
