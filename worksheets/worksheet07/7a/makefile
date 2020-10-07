all: clean overflow overflow_ssp

# Function gets() has been removed from C11 standard. 
# That means there's no longer a prototype for gets() in <stdio.h>. 
# -Wno-implicit-function-declaration required to quite the warning.

overflow_ssp:
	gcc -Wall -Wno-implicit-function-declaration -o overflow_ssp overflow.c

overflow:
	gcc -Wall -Wno-implicit-function-declaration -o overflow -fno-stack-protector overflow.c

clean:
	-rm overflow overflow_ssp