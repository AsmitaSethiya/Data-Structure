#include<stdio.h>

void primeseries(int);

void main()
{
    int number;
    printf("Enter the number: ");
    scanf("%d", &number);
    
    printf("\n2");
    primeseries(number - 1);
}

void primeseries(int a)
{
    static int n = 3;
    int i, flag = 0;
    
    if(a == 0)
    {
        printf("\nThe series ends here");
    }
    else
    {
        for(i = 2; i <= n - 1; i++)
        {
            if(n % i != 0)
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        
        if(flag)
        {
            printf("\n%d", n);
            n++;
            primeseries(a - 1);
        }
        else
        {
            n++;
            primeseries(a);
        }
    }
}
