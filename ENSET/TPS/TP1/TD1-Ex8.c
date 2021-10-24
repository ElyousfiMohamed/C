#include <stdio.h>
#include <stdlib.h>

long fibonacci(int n)
{
    if(n == 0 || n == 1)
        return 1;
    else
        return fibonacci(n-1)+fibonacci(n-2);
}

int main()
{
    int n;
    printf("n : ");
    scanf("%d",&n);
    printf("fibonacci(%d) = %d",n,fibonacci(n));
    return 0;
}
