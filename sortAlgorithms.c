#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *myArray, size_t len);

int main()
{
    int myArra2[10] = {60,81,298,93,44,675,4566,47,68,49};

    for (int i = 0; i<10; i++)
        printf("%d\t",myArra2[i]);

    printf("\n");
    bubbleSort(myArra2,10);

    for (int i = 0; i<10; i++)
        printf("%d\t",myArra2[i]);

    return 0;
}


void bubbleSort(int *myArray, size_t len)
{
    for(int i = 0; i<len; i++)
        for(int j = 0; j<len-1; j++)
            if (myArray[j]>myArray[j+1])
            {
                myArray[j]      ^=  myArray[j+1];
                myArray[j+1]    ^=  myArray[j];
                myArray[j]      ^=  myArray[j+1];
            }
}
