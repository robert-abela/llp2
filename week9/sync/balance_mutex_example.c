#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define THREAD_DELAY 	2
#define INIT_BALANCE 	100
#define WITHDRAW_AMOUNT 35
#define NUM_THREADS		4

pthread_mutex_t balance_mutex;
int balance = INIT_BALANCE;

/**
 * Reduces amount from the global balance. 
 * Returns the amount withdrawn if successful or -1 if refused.
 */
int withdraw(int amount) 
{
	pthread_mutex_lock(&balance_mutex);
	if (balance >= amount)
	{
		balance -= amount;
		pthread_mutex_unlock(&balance_mutex);
		return amount;
	}
	else
	{
		pthread_mutex_unlock(&balance_mutex);
		return -1;
	}
}

/**
 * Function to be used as a thread that attempts a withdrawal.
 */
void *try_to_withdraw(void *tid)
{
	int* thread_id = (int*)tid;
	sleep(THREAD_DELAY);
	printf("T %d: trying to withdraw %d\n", *thread_id, WITHDRAW_AMOUNT);
	if (withdraw(WITHDRAW_AMOUNT) == WITHDRAW_AMOUNT)
		printf("T %d: Successfully withdrawn\n", *thread_id);
	else
		printf("T %d: Failed to withdraw\n", *thread_id);

	return NULL;
}

/**
 * Main entry point: creates and launches 4 threads.
 */
int main()
{
	pthread_t threads[NUM_THREADS];
	int thread_ids[NUM_THREADS];

	if (sysconf(_SC_THREADS) == -1)
	{
		fprintf(stderr, "Error: Threads aren't supported.\n");
		return -1;
	}

	//initialise mutex
	pthread_mutex_init(&balance_mutex, NULL);

	//start all the threads
	for (int i=0; i<NUM_THREADS; i++)
	{
		thread_ids[i] = i+1;
		if (pthread_create(&threads[i], NULL, try_to_withdraw, &thread_ids[i]) != 0)
			fprintf(stderr, "Failed to create thread %d!\n", thread_ids[i]);
		else
			printf("Main: Thread %d started...\n", thread_ids[i]);
	}

	//wait for all threads to finish
	printf("Main: Wait for all threads to finish...\n\n");
	for (int j=0; j<NUM_THREADS; j++)
		pthread_join(threads[j], NULL);

	//destroy mutex and exit
	pthread_mutex_destroy(&balance_mutex);
	return 0;
}
