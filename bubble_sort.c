#include<stdio.h>

void main()
{
    int a[] = {40,20,50,10,30};
    int i, j, temp;
    
    printf("Before sorting the array is: ");
    for(i = 0 ; i < 5; i++)
    {
        printf("%d\t",a[i]);
    }
    
    for(i = 1; i < 5; i++)
    {
        for(j = 0; j < 5-i; j++)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    
    printf("\nSorted array is : ");
    for(i = 0; i < 5; i++)
    {
        printf("%d\t", a[i]);
    }
}
