#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void intercambioGenerico(void* a, void *b, size_t size);

int main()
{
    int one = 12;
    int two = 24;
    int *ptr1 = &one;
    int *ptr2 = &two;

    printf("Antes del cambio one=%d two=%d\n", *ptr1, *ptr2);
    intercambioGenerico(ptr1,ptr2,sizeof(int));
    printf("Antes del cambio one=%d two=%d\n",  *ptr1, *ptr2);

    char *wife = strdup("Wilma");
    char *hous = strdup("Fred");

    printf("Antes del cambio wife=%s hous=%s\n", wife, hous);
    intercambioGenerico(&wife,&hous,sizeof(char*));
    printf("Antes del cambio wife=%s hous=%s\n", wife, hous);

    return 0;
}

void intercambioGenerico(void* a, void *b, size_t size)
{
    char temp[size];
    memset(temp,'\0',size);
    memcpy(temp,a,size);
    memcpy(a,b,size);
    memcpy(b,temp,size);
}
