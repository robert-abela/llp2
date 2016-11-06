#include <stdio.h>

void f2(int age)
{
	int test = age-age;
	age = age / test;
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

