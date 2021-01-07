#include <stdio.h>
#include <unistd.h> /* sleep */
#include <pthread.h>

struct thread_arg {
	char *msg;
	int reps;
};

void* print_msg(void *ptr) {
	sleep(5); // seconds
	struct thread_arg* pargs = (struct thread_arg*)ptr;
	for (int i = 0; i < pargs->reps; i++)
		printf("Message from thread: %s \n", pargs->msg);
	return NULL;
}

int main(void) {
	pthread_t t1;
	
	struct thread_arg args;
	args.msg = "My msg";
	args.reps = 5;

	int r1 = pthread_create(&t1, NULL, print_msg, &args);
	printf("Thread 1 %s\n", r1 == 0 ? "created" : "failed");
	
	// Wait till threads are complete.
	pthread_join(t1, NULL);

	return 0;
}
