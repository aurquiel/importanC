#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *myArray, size_t len);
void quickSort(int *myArray, size_t left, size_t right);

int main()
{
    int myArra2[10] = {60,81,298,93,44,675,4566,47,68,49};

    for (int i = 0; i<10; i++)
        printf("%d\t",myArra2[i]);

    printf("\n");
    bubbleSort(myArra2,10);

    for (int i = 0; i<10; i++)
        printf("%d\t",myArra2[i]);
    
    int myArray[10] = { 3434,34343,665,6787,3423,4556,32323,787,1223};

    for(int i = 0; i<8; i++)
        printf("%d ",myArray[i]);

    printf("\n");
    quickSort(myArray,0,8);

    for(int i = 0; i<8; i++)
        printf("%d ",myArray[i]);

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

void quickSort(int *myArray, size_t left, size_t right)
{
    int i = left, j = right;
    int tmp;
    int pivot = myArray[(left + right) / 2];

    /* partition */

    while (i <= j)
    {
        while (myArray[i] < pivot)
            i++;

        while (myArray[j] > pivot)
            j--;

        if (i <= j)
        {
            tmp = myArray[i];
            myArray[i++] = myArray[j];
            myArray[j--] = tmp;
        }
    }

    /* recursion */
    if (left < j)
        quickSort(myArray, left, j);
    if (i < right)
        quickSort(myArray, i, right);
}
