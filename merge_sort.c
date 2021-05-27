#include<stdio.h>

void main()
{
    int a[] = {10, 20, 40, 60, 70} , b[] = {15, 25, 50, 80, 90}, c[10];
    int i = 0, j = 0, k = 0;
    
    while(i < 5 && j < 5)
    {
        if(a[i] < b[j])
        {
            c[k] = a[i];
            i++;
        }
        else
        {
            c[k] = b[j];
            j++;
        }
        k++;
    }
    
    while(i < 5)
    {
        c[k] = a[i];
        i++;
        k++;
    }
    
    while(j < 5)
    {
        c[k] = b[j];
        j++;
        k++;
    }
    
    for(i = 0; i < 10; i++)
    {
        printf("%d\t", c[i]);
    }
}
