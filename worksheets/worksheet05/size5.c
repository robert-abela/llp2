#include <stdio.h> 
long global = 10; /* Initialized global variable stored in DS */ 
int main(void)
{
	static long i = 100; /* Initialized static variable stored in DS */ 
	return 0; 
}