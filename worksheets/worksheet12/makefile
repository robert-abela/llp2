all: clean staticLinking staticLib useStaticLib dynLib

addDemo:
	gcc -I . -c addDemo.c

add:
	gcc -c add.c

sub:
	gcc -c sub.c

staticLinking: addDemo add
	$ gcc -o addDemo add.o addDemo.o

staticLib: sub add
	ar rs libheymath.a add.o sub.o

useStaticLib: staticLib
	gcc -I . -c addDemo2.c
	gcc -o addDemo2 addDemo2.o libheymath.a

dynLib:
	gcc -Wall -fPIC -c add.c
	gcc -Wall -fPIC -c sub.c
	gcc -shared -o libheymath.so add.o sub.o

clean:
	-rm *.o *.a addDemo addDemo2