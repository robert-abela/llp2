#include <stdio.h> 
 
void recurse(int level) 
{ 
    char arry[1024]; 
    printf("%d\n", level); 
    recurse(level+1); 
} 
 
int main() 
{
    recurse(1); 
    return 0; 
} 
