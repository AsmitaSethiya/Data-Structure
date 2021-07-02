#include<stdio.h>
int power(int, int);

void main()
{
    int n, p, result;
    
    printf("Enter a number: ");
    scanf("%d", &n);
    
    printf("Enter the power to be calculated: ");
    scanf("%d", &p);
    
    result = power(n, p);
    
    printf("The result of %d to power of %d is %d", n, p, result);
}

int power(int n, int p)
{
    static int i = 1;
    
    if(p == 0)
    {
        return 1;
    }
    else
    {
        i  = i * n;
        power(n, p -1);
    }
    
    return i;
}
