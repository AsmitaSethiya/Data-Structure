#include<stdio.h>

void insert(int[], int);
void Delete(int[], int);
void traversal(int[], int);

void main()
{
    int a[100] = {10, 20, 30, 40, 50};
    
    int size  = 5, choice;
    
    traversal(a, size);
    
    do
    {
        printf("\n**************Array Operations*************\n");
        
        printf("Enter 1 to insert element in array\n");
        printf("Enter 2 to Delete element from array\n");
        printf("Enter 3 to traverse the array\n");
        printf("Enter 4 to exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                insert(a, size);
                size++;
                break;
            case 2:
                Delete(a, size);
                size--;
                break;
            case 3:
                traversal(a, size);
                break;
            case 4:
                break;
            default:
                printf("\nInvalid choice, Please enter valid choice\n");
                break;
        }
    }
    while(choice != 4);
}

void insert(int a[], int size)
{
    int element,  position;
    
    printf("Enter integer to be inserted: ");
    scanf("%d", &element);
    
    printf("Enter position in the array for insertion: ");
    scanf("%d", &position);
    
    for(int i = size - 1; i >= position; i--)
    {
        a[i + 1] = a[i];
    }
    
    a[position] = element;
    
    
    printf("\nElement %d is inserted successfully\n", element);
}

void Delete(int a[], int size)
{
    int position;
    
    printf("On which position element you want to delete: ");
    scanf("%d", &position);
    
    for(int i = position; i < size - 1; i++)
    {
        a[i] = a[i + 1];
    }
    
    printf("\nDeletion done successfully\n");
}

void traversal(int a[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d\t", a[i]);
    }
}
