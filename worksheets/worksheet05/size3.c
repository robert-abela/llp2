#include <stdio.h> 
int global; /* Uninitialized variable stored in BSS */
int main(void)
{
	static int i; /* Uninitialized static variable stored in BSS */
	return 0;
}