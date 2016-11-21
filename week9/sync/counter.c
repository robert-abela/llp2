#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 5
#define ITERATIONS 50000

int x = 0;

/* Increments X 1000 times */
void *do_work(void *tid)
{
	for (int k=0; k < ITERATIONS; k++)
		x = x + 1; // (WARNING: RACE CONDITION)

	return NULL;
}

void try()
{
	pthread_t threads[NUM_THREADS];

	//start all the threads
	for (int i=0; i<NUM_THREADS; i++)
		if (pthread_create(&threads[i], NULL, do_work, NULL) != 0)
			fprintf(stderr, "Failed to create a thread!\n");

	//wait for all threads to finish
	for (int j=0; j<NUM_THREADS; j++)
		pthread_join(threads[j], NULL);
}

/** Launches NUM_THREADS threads that try to increment x to NUM_THREADS*ITERATIONS */
int main()
{
	try();
	printf("x = %d\n", x);
	return 0;
}