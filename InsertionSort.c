#include<stdio.h>

void main()
{
    
    int a[] =  {50, 40, 20, 10, 30};
    
    int i, j, temp;
    
    printf("Before Sorting\n");
    
    for(i = 0; i <= 4; i++)
    {
        printf("%d\t", a[i]);
    }
    
    for(i = 1; i < 5; i++)
    {
        j = i - 1;
        temp = a[i];
        while(j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
    
    printf("\nAter Insertion Sort\n");
    
    for(i = 0; i <= 4; i++)
    {
        printf("%d\t",a[i]);
    }
}
