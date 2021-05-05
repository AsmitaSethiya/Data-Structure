#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node *add;
};

struct node *start = NULL, *temp = NULL, *prev = NULL, *next = NULL, *NEW = NULL;

//Declaration of functios
void Create();
void Insert();
void Delete();
void Display();

void main()  // start of main function
{
    int choice;
    
    do{
    printf("\n---------------***Circular Linked List**-------------\n");
    
    printf("Enter 1 for Create List\n");
    
    printf("Enter 2 for Insert element in linked list\n");
    
    printf("Enter 3 for Delete element in Linked List\n");
    
    printf("Enter 4 for Display element\n");
    
    printf("Enter 5 for Exit\n");
    
    printf("Enter your choice: ");
    scanf("%d",&choice);
    
    switch(choice)
        {
            case 1:
                Create();
                break;
            case 2:
                Insert();
                break;
            case 3:
                Delete();
                break;
            case 4:
                Display();
                break;
            case 5:
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    while(choice!=5);
}  // end of main function

void Create()   // start of Create function
{
    int n;
    char ch;
    
    printf("Enter a value: ");
    scanf("%d",&n);
    
    start = (struct node *)malloc(sizeof(struct node));
    
    start -> data = n;
    start -> add = start;
    temp = start;
    
    printf("\nTo add more element, Press 'Y': ");
    scanf(" %c",&ch);
    
    while(ch == 'y' || ch == 'Y')
    {
        printf("Enter next value: ");
        scanf("%d",&n);
        
        NEW = (struct node *)malloc(sizeof(struct node));
        
        NEW -> data = n;
        NEW -> add = start;
        temp -> add = NEW;
        temp = NEW;
        
        printf("\nto add more element, Press 'Y': ");
        scanf(" %c",&ch);
    }
}     // end of Create function

void Insert()  // start of Insert function
{
    int position, i = 1, count = 0, n;
    
    if (start == NULL)
    {
        printf("list is empty");
    }
    else
    {
        printf("Enter a value: ");
        scanf("%d",&n);
        
        NEW = (struct node *)malloc(sizeof(struct node));
        
        NEW -> data = n;
        NEW -> add = start;
        
        printf("Enter a position for insretion: ");
        scanf("%d",&position);
        
        if(position == 1)
        {
            temp = start;
            while(temp -> add != start)
            {
                temp = temp -> add;
            }
            temp -> add = NEW;
            start = NEW;
            
        }
        else 
        {
            temp = start;
            do
            {
                count++;
                temp = temp -> add;
            }
            while(temp != start);
           
            if(position > count + 1)
            {
                printf("invalid position, it can not be more than %d",(count+1));
            }
            else if(position == (count + 1))
            {
                temp = start;
                while (temp -> add != start)
                {
                    temp = temp -> add;
                }
                
                temp -> add = NEW;
            }
            else
            {
                next = start;
                
                while(i < position)
                {
                    prev = next;
                    next = next -> add;
                    i++;
                }
                
                prev -> add = NEW;
                NEW -> add = next;
            }
        }
    }
}        // end of Insert function

void Delete()      // start of Delete function
{
    int position, count = 0, i = 1;
    
    if(start == NULL)
    {
        printf("List is not created, Please create list first............\n");
    }
    else
    {
        printf("Enter the position to Delete the element: ");
        scanf("%d",&position);
        
        if(position == 1)
        {
            prev = start;
            start = start -> add;
            temp = prev;
            
            printf("Deleted element is:%d",temp -> data);
            while(temp -> add != prev)
            {
                temp = temp -> add;
            }
            temp -> add = start;
            free(prev);
        }
        else
        {
            temp = start;
            do
            {
                count++;
                temp = temp -> add;
            }
            while(temp != start);
            
            if(position > count)
            {
                printf("Invalid position, it can not be more than %d\n",count);
            }
            else if(position == count)
            {
                next = start;
                while(next -> add != start)
                {
                    prev = next;
                    next = next -> add;
                }
                printf("Deleted element is:%d",next -> data);
                prev -> add = start;
                free(next);
            }
            else
            {
                next = start;
                while(i < position)
                {
                    prev = next;
                    next = next -> add;
                    i++;
                }
                temp = next;
                next = next -> add;
                printf("Deleted element is:%d\n",temp -> data);
                prev -> add = next;
                free(temp);
            }
            
        }
    }
}      // end of Delete function


void Display()  // Display() start
{
    temp = start;
   do
   {
       printf("%d\t",temp -> data);
       temp = temp -> add;
   }
   while(temp != start);
}    //Display() end




