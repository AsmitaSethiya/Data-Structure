#include<stdio.h>

int table(int, int);

void main()
{
    int i , n;
    
    printf("Enter any integer: ");
    scanf("%d",&n);
    
    for(i = 1; i <= 10; i++)
    {
        printf("%d * %d = %d\n", n, i ,table(n , i));
    }
}

int table(int n, int i)
{
    if(i == 1)
    {
        return n;
    }
    else
    {
        return (table(n, i - 1) + n);
    }
}
