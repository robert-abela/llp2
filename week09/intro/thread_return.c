#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* vargp is not used, NULL should be passed */
void *thread1(void *vargp) {
	return (void*)42;
	//pthread_exit((void*)42);
}

/* vargp is not used, NULL should be passed */
void *thread2(void *vargp) {
	int* ptr_i = (int*)malloc(sizeof(int));
	*ptr_i = 42;
	return (void*)ptr_i;
}

int main(void) {
	int integer = 10;
	int *ptr_integer = NULL;
	pthread_t t1, t2;

	pthread_create(&t1, NULL, thread1, NULL);
	pthread_create(&t2, NULL, thread2, NULL);

	pthread_join(t1, (void**) &integer);
	pthread_join(t2, (void**) &ptr_integer);
	
	printf("i1 = %d\n", integer);
	printf("i2 = %d\n", *ptr_integer);

	free(ptr_integer);
	return 0;
}
