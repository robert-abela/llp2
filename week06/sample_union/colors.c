#include <stdio.h>

struct rgba {
  unsigned char red;
  unsigned char green;
  unsigned char blue;
  unsigned char alpha;
};

union color32bit {  
  unsigned int value;
  struct rgba components;
};

int main (int argc, char* argv[]) {

	/*You can use both the 32-bit value but also the individual 4 components*/
	union color32bit my_col;   
	my_col.components.red   = 0x88;   
	printf("Hex for purple: 0x%x\n",my_col.value);
	my_col.components.green = 0x11;   
	printf("Hex for purple: 0x%x\n",my_col.value);
	my_col.components.blue  = 0x88;       
	printf("Hex for purple: 0x%x\n",my_col.value);
	my_col.components.alpha = 0x11;
	printf("Hex for purple: 0x%x\n",my_col.value);

	my_col.value = 0x00FF00AA;
	
	printf("R: %i\n",my_col.components.red);
	printf("G: %i\n",my_col.components.green);
	printf("B: %i\n",my_col.components.blue);
	printf("A: %i\n",my_col.components.alpha);

	return 0;
}
