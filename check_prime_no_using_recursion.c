#include<stdio.h>

int prime(int);

void main()
{
    int n, f = 0;
    
    printf("Enter the number: ");
    scanf("%d", &n);
    
    if(n == 2)
    {
        printf("The number is prime");
    }
    else if(n < 2)
    {
        printf("The smallest prime number is 2");
    }
    else
    {
        f = prime(n);
        
        if(f)
        {
            printf("Number is Prime");
        }
        else
        {
            printf("Non Prime");
        }
    }
}


int prime(int n)
{
    static int i = 2, flag = 1;
    
    if(i == n)
    {
        return 0;
    }
    else
    {
        if(n % i == 0)
        {
            flag = 0;
            i++;
        }
        else
        {
            i++;
            flag = 1;
            prime(n);
        }
    }
    
    
    return flag;
}
