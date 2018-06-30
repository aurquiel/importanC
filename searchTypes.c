#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int linearSearch(int *pArray, size_t len, int long long value);
int busquedaBinaria(int *myArray, size_t len, int key);

int main()
{
    int myArray[10] = {0,1,2,3,4,5,6,7,8,9};

    printf("%d\n",linearSearch(myArray,10,4));
    printf("%d\n", busquedaBinaria(myArray,10,3));

    return 0;
}

int linearSearch(int pArray[], size_t len, int long long value)
{
    for (size_t index = 0; index++<len; )
        if (*(pArray++) == value)
            return index;
    return -1;
}

int busquedaBinaria(int *myArray, size_t len, int key)
{
    int mid = 0, low = 0, high = len -1;
    while(low <= high)
    {
        mid = (high+low)/2;
        if (*(myArray+mid) == key)
            return mid;
        else if (*(myArray+mid) < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
