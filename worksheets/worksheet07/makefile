all: clean overflow overflow_spp

# Function gets() has been removed from C11 standard. 
# That means there's no longer a prototype for gets() in <stdio.h>. 
# -Wno-implicit-function-declaration required to quite the warning.

overflow_spp:
	gcc -Wall -Wno-implicit-function-declaration -o overflow_spp overflow.c

overflow:
	gcc -Wall -Wno-implicit-function-declaration -o overflow -fno-stack-protector overflow.c

clean:
	-rm overflow overflow_spp