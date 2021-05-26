#include<stdio.h>

void qsort(int[], int , int);
int split(int[], int, int);

void main()
{
    int a[] = {44, 33, 11, 55, 77, 90, 40, 60, 99, 22, 88, 66}, i;
    
    printf("Before sorting the array is: ");
    for(i = 0; i < 12; i++)
    {
        printf("%d\t", a[i]);
    }
    
    qsort(a,0,11);
    
    printf("\nAfter sorting the array is: ");
    for(i = 0; i < 12; i++)
    {
        printf("%d\t",a[i]);
    }
}


void qsort(int a[], int lower, int upper)
{
    int i;
    if (upper > lower)
    {
        i = split(a, lower, upper);
        qsort(a, lower, (i - 1));
        qsort(a, (i + 1), upper);
    }
}

int split(int a[], int lower, int upper)
{
    int p, l, r, temp;
    l = lower + 1;
    r = upper;
    p = a[lower];
    
    while(r >= l)
    {
        while(a[l] < p)
        {
            l++;
        }
        while(a[r] > p)
        {
            r--;
        }
        if (r > l)
        {
            temp = a[l];
            a[l] = a[r];
            a[r] = temp;
        }
    }
    
    
    temp = a[lower];
    a[lower] = a[r];
    a[r] = temp;
    
    return r;
    
}
