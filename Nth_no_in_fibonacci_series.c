#include<stdio.h>

int fibonacci(int);

void main()
{
    int p, num;
    
    printf("Enter the position of element you want from fibonacci series: ");
    scanf("%d", &p);
    
    num = fibonacci(p);
    printf("The required fibonacci number is: %d", num);
}

int fibonacci(int p)
{
    if(p == 1 || p == 0)
    {
        return p;
    }
    else
    {
        return (fibonacci(p - 1) + fibonacci(p - 2));
    }
}
