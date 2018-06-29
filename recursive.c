#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t factorial( int num);
size_t fibonacci(int num);
size_t fibonacciIterativo(int num);

int main()
{
    size_t num = factorial(2);
    size_t num2 = fibonacci(10);
    size_t num3 = fibonacciIterativo(10);

    printf("%u\n", num);
    printf("%u\n", num2);
    printf("%u\n", num3);

    return 0;
}

size_t factorial(int num)
{
    if (num == 0)
        return 1;
    else
        return num*factorial(num -1);
}

size_t fibonacci(int num)
{
    if(num < 2)
      return 1;
    else
        return fibonacci(num-1)+fibonacci(num-2);
}

size_t fibonacciIterativo(int num)
{
    size_t a = 0, b = 1,c;
    size_t i;
    for ( i = 0; i<num; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
