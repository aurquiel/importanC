#include <stdio.h>
#include <stdlib.h>

int main()
{
    int myArray [3][3] = { {234,456,78}, {-45, 576, -34}, {-34, 56667, 12} };

    int (*myPtr) = myArray[0];
    int (*myPtr2)[3] =myArray;

    for(int i = 0; i<9; i++)
        printf("%d ",*(myPtr+i));

    printf("\n");

    for(int i = 0; i<9; i+=3)
        for (int j = 0; j <3; j++)
        {
            printf("%d ",*((*myPtr2+i)+j));
            printf("\n i=%d j=%d\n",i,j);
        }


    return 0;
}
