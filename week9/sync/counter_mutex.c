#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5
#define ITERATIONS 50000

int counter = 0;
pthread_mutex_t counter_mutex;

/* Increments X ITERATIONS times */
void *do_work(void *ptr)
{
	for (int k=0; k<ITERATIONS; k++)
	{
		pthread_mutex_lock(&counter_mutex);
		counter = counter + 1;
		pthread_mutex_unlock(&counter_mutex);
	}
	
	return NULL;
}

/** Launches NUM_THREADS threads to increment counter to NUM_THREADS*ITERATIONS */
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

int main()
{
	//initialise mutex
	pthread_mutex_init(&counter_mutex, NULL);
	
	try();
	
	//destroy mutex and exit
	pthread_mutex_destroy(&counter_mutex);

	printf("counter = %d\n", counter);
	return 0;
}
