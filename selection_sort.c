#include<stdio.h>

void main()
{
    int a[] = {40, 50, 30, 10, 20};
    int i, j, temp, min, pos;
    
    printf("Before sorting the array is: ");
    
    for(i = 0; i < 5; i++)
    {
        printf("%d\t", a[i]);
    }
    
    for(i = 0; i < 4; i++)
    {
        min = a[i];
        pos = i;
        
        for(j = (i + 1); j < 5; j++)
        {
            if(min > a[i])
            {
                min = a[i];
                pos = j;
            }
            
            if(i != pos)
            {
                temp = a[i];
                a[i] = a[pos];
                a[pos] = temp;
            }
        }
    }
    
    
    printf("\nAfter sorting the array is: ");
    for(i = 0; i < 5; i++)
    {
        printf("%d\t",a[i]);
    }
}
