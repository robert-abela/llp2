#include <stdio.h>

#define ROWS 10
#define STAR '*'

/* Adapted from: http://www.programering.com/a/MTOyEDMwATY.html*/
int main()
{
    int starNo,spaceNo;

    for (int i=1; i<=ROWS; i++)
    {
        starNo=i*2-1;
        spaceNo=i+ROWS-starNo;
        for(int j=0; j<spaceNo; j++)
             printf(" ");
        for(int k=0; k<starNo; k++)
            printf("%c",STAR);
        printf("\n");
    }

    for (int l=0; l<3; l++)
    {
        for(int m=0; m<(ROWS*2+1)/2; m++)
            printf(" ");
        printf("%c\n",STAR);
    }

    return 0;
}
