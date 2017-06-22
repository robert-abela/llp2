#include <stdio.h>
#include <stdlib.h>
#include <phtread.h>

void *thread1(void *vargp)
{
	return (void*)42;
	//pthread_exit((void*)42);
}

void *thread2(void *vargp)
{
	int* i = (int*)malloc(sizeof(int));
	*i = 42;
	return (void*)i;
}

int main()
{
	int i1 = 0;
	int *i2 = NULL;
	pthread_t t1, t2;

	pthread_create(&t1, NULL, thread1, NULL);
	pthread_create(&t2, NULL, thread2, NULL);
	
	pthread_join(t1, (void**)&i1);
	pthread_join(t2, (void**)i2);
	printf("i1 = %d\n", i1);
	printf("i2 = %d\n", *i2);

	free(i2);
}