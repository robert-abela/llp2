#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define DELAY 2
#define BALANCE 100
#define WITHDRAW_AMOUNT 40

pthread_mutex_t balance_mutex;
int balance = BALANCE;

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
		return 0;
	}
}

void *try_to_withdraw(void *argument)
{
	int* thread_id = (int*)argument;
	printf("Thread%d: waiting for %d seconds...\n", *thread_id, DELAY);
	sleep(DELAY);
	printf("Thread%d: trying to withdraw %d\n", *thread_id, WITHDRAW_AMOUNT);
	if (withdraw(WITHDRAW_AMOUNT) == WITHDRAW_AMOUNT)
		printf("Thread%d: Successfully withdrawn\n", *thread_id);
	else
		printf("Thread%d: Failed to withdraw\n", *thread_id);

  	return NULL;
}

int main()
{ 
	pthread_t threads[3];
	int thread_ids[] = {1,2,3};

	if (sysconf(_SC_THREADS) == -1)
	{
  		fprintf(stderr, "Error: Threads aren't supported.\n");
    	return -1;
   	}

   	//initialise mutex
  	pthread_mutex_init(&balance_mutex, NULL);

  	//start all the threads
  	for (int i=0; i < 3; i++)
  	{
  		if (pthread_create(&threads[i], NULL, try_to_withdraw, &thread_ids[i]) != 0)
	    	fprintf(stderr, "Failed to create thread %d!\n", thread_ids[i]);
	    else
	    	printf("Main: Thread %d started...\n", thread_ids[i]);
  	}

  	//wait for all threads to finish
	printf("Main: Wait for all threads to finish...\n\n");
  	for (int i=0; i < 3; i++)
  		pthread_join(threads[i], NULL);

  	//destroy mutex and exit
  	pthread_mutex_destroy(&balance_mutex);
  	return 0;
}