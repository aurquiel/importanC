#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int linearSearch(int *pArray, size_t len, int long long value);
int busquedadBinaria(int pArray[], size_t len, int long long value);

int main()
{
    int myArray[10] = {0,1,2,3,4,5,6,7,8,9};

    printf("%d\n",linearSearch(myArray,10,4));
    printf("%d\n", busquedadBinaria(myArray,10,3));

    return 0;
}

int linearSearch(int pArray[], size_t len, int long long value)
{
    for (size_t index = 0; index++<len; )
        if (*(pArray++) == value)
            return index;
    return -1;
}

int busquedadBinaria(int pArray[], size_t len, int long long value)
{
    int limiteZ = 0, limiteD = len;
    while(limiteZ < limiteD)
    {
        int mid = (limiteZ+limiteD)/2;

        if(pArray[mid] == value)
            return ++mid;
        else if (pArray[mid] < value)
            limiteZ = mid + 1;
        else
            limiteD = mid - 1;

    }
    return -1;
}
