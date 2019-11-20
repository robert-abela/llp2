#include <stdio.h>
#include <unistd.h> /* sleep */
#include <pthread.h>

void* print_msg(void *ptr) {
	sleep(5); // seconds
	printf("Message from thread: %s \n", (char*)ptr);
	return NULL;
}

int main(void) {
	pthread_t t1, t2;
	char *msg1 = "Thread One", *msg2 = "Thread Two";

	// Create 2 threads, passings the strings as params
	int r1 = pthread_create(&t1, NULL, print_msg, msg1);
	int r2 = pthread_create(&t2, NULL, print_msg, msg2);

	printf("Thread 1 %s\n", r1 == 0 ? "created" : "failed");
	printf("Thread 2 %s\n", r2 == 0 ? "created" : "failed");

	// Wait till threads are complete.
	pthread_join(t1, NULL);
	pthread_join(t2, NULL); 

	return 0;
}
