#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *ladd;
    struct node *radd;
};

struct node *start = NULL, *temp = NULL, *prev = NULL, *next = NULL, *NEW = NULL;

void Create();
void Insert();
void Delete();
void Display();

void main()
{
    int choice;
    
    do
    {
        printf("\n*************Doubly Linked List*************\n");
        
        printf("Enter 1 to Create Doubly Linked List\n");
        
        printf("Enter 2 to insert node in Doubly Linked List\n");
        
        printf("Enter 3 to delete node from Doubly Linked List\n");
        
        printf("Enter 4 to Display elements of Linked List\n");
        
        printf("Enter 5 for EXIT\n");
        
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
                printf("\nInvalid Choice, Please Re-Enter your choice..........");
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
    start -> ladd = NULL;
    start -> radd = NULL;
    temp = start;
    
    printf("\nTo add more elements,Press 'Y': ");
    scanf(" %c",&ch);
    
    while(ch == 'Y' || ch == 'y')
    {
        printf("Enter next value: ");
        scanf("%d",&n);
        
        NEW = (struct node *)malloc(sizeof(struct node));
        
        NEW -> data = n;
        NEW -> ladd = temp;
        NEW -> radd = NULL;
        temp -> radd = NEW;
        temp = NEW;
        
        printf("To add more elements, Press 'Y': ");
        scanf(" %c",&ch);
    }
}

void Insert()
{
    int n, position, i = 1, count = 0;
    
    if(start == NULL)
    {
        printf("List is not create, First create list.............\n");
    }
    else
    {
        printf("Enter a value: ");
        scanf("%d",&n);
        
        NEW  = (struct node *)malloc(sizeof(struct node));
        
        NEW -> data = n;
        NEW -> ladd = NULL;
        NEW -> radd = NULL;
        
        printf("Enter the position for node insertion: ");
        scanf("%d",&position);
        
        if(position == 1)
        {
            NEW -> radd = start;
            start -> ladd = NEW;
            start = NEW;
        }
        else
        {
            temp = start;
            
            while(temp != NULL)
            {
                count++;
                temp = temp -> radd;
            }
            
            if(position > (count +1))
            {
                printf("Invalid position , I can not be more than %d",(count + 1));
            }
            else if(position == count + 1)
            {
                temp = start;
                while(temp -> radd != NULL)
                {
                    temp = temp -> radd;
                }
                temp -> radd = NEW;
                NEW ->ladd = temp;
            }
            else
            {
                temp = start;
                while(i < position)
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
    int position, count = 0 , i = 1;
    
    if(start == NULL)
    {
        printf("List is not created, First create list first\n");
    }
    else
    {
        printf("Enter  position: ");
        scanf("%d",&position);
        
        if(position == 1)
        {
            printf("Deleted element is: %d",start -> data);
            start = start -> radd;
            free(start -> ladd);
            start -> ladd = NULL;
        }
        else
        {
            temp = start;
            
            while(temp != NULL)
            {
                count++;
                temp = temp -> radd;
            }
            
            if(position > count)
            {
                printf("Invalid Positiion, it can not be more than %d",count);
            }
            else if(position == count)
            {
                temp = start;
                
                while(temp -> radd != NULL)
                {
                    temp = temp -> radd;
                }
                temp -> ladd -> radd = NULL;
                printf("Deleted element is: %d",temp -> data);
                free(temp);
            }
            else
            {
                temp = start;
                
                while(i < position)
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
    temp = start;
    
    while(temp != NULL)
    {
        printf("%d\t",temp -> data);
    
        temp = temp -> radd;
    }
}
