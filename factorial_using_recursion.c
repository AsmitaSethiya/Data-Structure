#include<stdio.h>

int fact(int);

void main()
{
    int n ,result;
    
    printf("Enter a number: ");
    scanf("%d", &n);
    
    result = fact(n);
    printf("%d", result);
}

int fact(int n)
{
    if(n == 1)
    {
        return n;
    }
    else
    {
        return (n * fact(n - 1));
    }
}
