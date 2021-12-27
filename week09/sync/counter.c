#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5
#define ITERATIONS 50000

int counter = 0;

/* Increments counter ITERATIONS times */
void *do_work(void *ptr) {
	for (int k=0; k<ITERATIONS; k++)
		counter = counter + 1;

	return NULL;
}

/** Launches NUM_THREADS threads that try to increment counter to NUM_THREADS*ITERATIONS */
void try(void) {
	pthread_t threads[NUM_THREADS];

	//start all the threads
	for (int i=0; i<NUM_THREADS; i++)
		if (pthread_create(&threads[i], NULL, do_work, NULL) != 0)
			fprintf(stderr, "Failed to create a thread!\n");

	//wait for all threads to finish
	for (int j=0; j<NUM_THREADS; j++)
		pthread_join(threads[j], NULL);
}

int main(void) {
	try();
	printf("counter = %d\n", counter);
	return 0;
}
