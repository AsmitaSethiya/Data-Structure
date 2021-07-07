#include<stdio.h>

void main()
{
    int a[3][3] , i, j;
    
    printf("\nEnter the element array: ");
    
    
    for(i = 0; i <= 2; i++)
    {
        for(j = 0; j <= 2; j++)
        {
            printf("Enter element at %d%d position: ", i, j);
            scanf("%d", &a[i][j]);
        }
        
        printf("\n");
    }
    
    printf("\n");
    
    printf("The elements of array are.......\n");
    
    for(i = 0; i <= 2; i++)
    {
        for(j = 0; j <= 2; j++)
        {
            printf("%d\t",a[i][j]);
        }
    }
}
