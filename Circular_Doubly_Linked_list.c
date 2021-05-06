#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *ladd;
    struct node *radd;
};

struct node *start = NULL, *temp = NULL, *NEW = NULL, *prev  = NULL, *next = NULL;

void Create();
void Insert();
void Delete();
void Display();

void main()
{
    int choice;
    
    do
    {
        printf("\n**********Circular Doubly Linked List**************\n");
        
        printf("Enter 1 to Create  Circular Doubly Linked List\n");
        
        printf("Enter 2 to Insert node in Circular Doubly Linked List\n");
        
        printf("Enter 3 to Delete node from Circular Doubly Linked List\n");
        
        printf("Enter 4 to Display elements of Circular Doubly Linked List\n");
        
        printf("Enter 5 fot Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
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
                printf("Invalid Position, Please enter valid Position...........\n");
        }
    }
    while(choice != 5);
}


void Create()
{
    int n;
    char ch;
    
    printf("Enter a value: ");
    scanf("%d",&n);
    
    start = (struct node *)malloc(sizeof(struct node));
    
    start -> data = n;
    start -> ladd = start;
    start -> radd = start;
    temp = start;
    
    printf("To add more elements , Press 'Y': ");
    scanf(" %c",&ch);
    
    while(ch == 'y' || ch == 'Y')
    {
        printf("Enter next value: ");
        scanf("%d",&n);
        
        NEW = (struct node *)malloc(sizeof(struct node));
        
        temp -> radd = NEW;
        NEW -> data  = n;
        NEW -> ladd = temp;
        NEW -> radd = start;
        start -> ladd = NEW;
        temp = NEW;
        
        printf("\nTo add more elements, Press 'Y': ");
        scanf(" %c",&ch);
    }
}

void Insert()
{
    int Position, n, i = 1, count = 0;
    
    if(start == NULL)
    {
        printf("List is not created, First create List......\n");
    }
    else
    {
        printf("Enter a value: ");
        scanf("%d",&n);
        
        NEW = (struct node *)malloc(sizeof(struct node));
        
        NEW -> data = n;
        NEW -> ladd = start;
        NEW -> radd = start;
        
        printf("Enter Position: ");
        scanf("%d",&Position);
        
        if(Position == 1)
        {
            temp = start;
            
            while(temp -> radd != start)
            {
                temp = temp -> radd;
            }
            
            NEW -> radd = start;
            start -> ladd = NEW;
            NEW -> ladd = temp;
            temp -> radd = NEW;
            start = NEW;
        }
        else
        {
            temp = start;
            
            do
            {
                count++;
                temp = temp -> radd;
            }
            while(temp != start);
            
            if(Position > count + 1)
            {
                printf("Invalid Position,it can not be more than %d",count + 1);
            }
            else if(Position == count + 1)
            {
                temp = start;
                
                while(temp -> radd != start)
                {
                    temp = temp -> radd;
                }
                temp -> radd = NEW;
                NEW -> ladd = temp;
                start -> ladd = NEW;
            }
            else
            {
                temp = start;
                
                while(i < Position)
                {
                    temp = temp -> radd;
                    i++;
                }
                 temp -> ladd -> radd = NEW;
                NEW -> ladd = temp -> ladd;
                NEW -> radd = temp;
                temp -> ladd = NEW;
            }
        }
    }
}

void Delete()
{
    int Position , i = 1, count = 0;
    
    if(start == NULL)
    {
        printf("List is not created, First create list......\n");
    }
    else
    {
        printf("Enter Position: ");
        scanf("%d",&Position);
        
        if(Position == 1)
        {
            temp = start;
            
            while(temp -> radd != start)
            {
                temp = temp -> radd;
            }
            
            printf("Deleted element is: %d",start -> data);
            start = start -> radd;
            free(start -> ladd);
            start -> ladd = temp;
            temp -> radd = start;
        }
        else
        {
            temp = start;
            
             do
            {
                count++;
                temp = temp -> radd;
            }
            while(temp != start);
            
            if(Position > count)
            {
                printf("Invalid Position, It can not be more than: %d", count);
            }
            else if(Position == count)
            {
                temp = start;
                
                while(temp -> radd != start)
                {
                    temp = temp -> radd;
                }
                
                temp -> ladd -> radd = start;
                start -> ladd = temp -> ladd;
                printf("Deleted element is: %d",temp -> data);
                free(temp);
            }
            else
            {
                temp = start;
                
                while(i < Position)
                {
                    temp = temp -> radd;
                    i++;
                }
                
                temp -> ladd -> radd = temp -> radd;
                temp -> radd -> ladd = temp -> ladd;
                printf("Deleted element is: %d",temp -> data);
                free(temp);
            }
            
        }
    }
}

void Display()
{
    temp = start ;
    do
    {
        printf("%d\t",temp -> data);
        temp =temp -> radd;
    }
    while(temp != start);
}
