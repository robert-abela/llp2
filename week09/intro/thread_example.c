#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* background_task(void *ptr) {
	printf("Printing from the thread!\n");
	return NULL;
}

int main(void) {
	pthread_t 	mythread;
	int			result;

	/*if (sysconf(_SC_THREADS) == -1) {
		fprintf(stderr, "Sorry, this program requires threads, which aren't supported here.\n");
		return -1;
	}*/

	result = pthread_create(&mythread, NULL, background_task, NULL);

	if (result != 0) {
		fprintf(stderr, "For some reason I couldn't create a thread! (errno = %d)\n", result);
		return -2;
	}

	pthread_join(mythread, NULL);
	return 0;
}
