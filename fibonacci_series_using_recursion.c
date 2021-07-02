#include<stdio.h>

void fseries(int);

void main()
{
    int limit, f0 = 0, f1 = 1;
    
    printf("Enter the limit of fibonacci number: ");
    scanf("%d", &limit);
    
    if(limit > 2)
    {
        printf("%d\t %d\t", f0, f1);
        fseries(limit - 2);
    }
    else if(limit == 2)
    {
        printf("\n %d \t %d", f0, f1);
    }
    else if(limit == 1)
    {
        printf("%d", f1);
    }
    else 
    {
        printf("series not possible\n");
    }
}


void fseries(int n)
{
    int temp ;
    static int f0 = 1, f1 = 1;
    if(n == 0)
    {
        printf("\nThe series ends here\n");
    }
    else
    {
        temp = f0 + f1;
        printf("%d\t", temp);
        f0 = f1;
        f1 = temp;
        fseries(n - 1);
    }
}
