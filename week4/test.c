#include <stdio.h>

void f2(int age)
{
	int zero = 0;
	age = age / zero;
}
void f1(int age)
{
	int local = 10;
	f2(age+local);
}
int main(int argc, char **argv)
{
	int age = 33;
	f1(age);
    return 0;
}

