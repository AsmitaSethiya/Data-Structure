#include<stdio.h>

int reverseint(int);

void main()
{
    int num, result;
    
    printf("Enter  a number: ");
    scanf("%d", &num);
    
    result = reverseint(num);
    
    printf("The reverse number of %d is: %d", num , result);
}

int reverseint(int num)
{
    int r;
    static int rev = 0;
    
    if(num == 0)
    {
        return num;
    }
    else
    {
        r = num % 10;
        rev = rev * 10 + r;
        reverseint(num / 10);
    }
    
    return(rev);
}
