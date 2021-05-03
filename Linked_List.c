#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node *add;
};

struct node *start = NULL, *temp = NULL, *New = NULL, *next = NULL, *prev = NULL;

// function declaration
void Create();
void Insert();
void Delete();
void Display();
void Reverse();
void minElement();
void maxElement();
void ElementSearch();

void main() // start of main function
{
    int choice;
    
    do{
        
        printf("\n******************LINKED LIST********************\n");
        
        printf("Enter 1 to create Linked List\n");
        
        printf("Enter 2 to insert the element into Linked List\n");
        
        printf("Enter 3 to Delete the element from Linked List\n");
        
        printf("Enter 4 to Display all elements from Linked List\n");
        
        printf("Enter 5 to reverse the linked list\n");
        
        printf("Enter 6 to find minimum element in Linked list\n");
    
        printf("Enter 7 to find maximum element in linked list\n");
    
        printf("Enter 8 to search element in Linked List\n");
    
        printf("Enter 9 for Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                Create();       // function calling
                break;
            case 2:
                Insert();       // function calling
                break;
            case 3:
                Delete();       // function calling
                break;
            case 4:
                Display();      // function calling
                break;
            case 5:
                Reverse();
                break;
            case 6:
                minElement();
                break;
            case 7:
                maxElement();
                break;
            case 8:
                ElementSearch();
                break;
            case 9:
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    while(choice != 9);
}   // end of main function

// function definition
void Create()         // start of Create function                                                         
{
    int n;
    char ch;
    
    printf("Enter a value: ");
    scanf("%d",&n);
    
    start = (struct node *)malloc(sizeof(struct node));
    
    start -> data = n;
    start -> add = NULL;
    temp = start;
    
    printf("To add more element, Press 'Y': ");
    scanf(" %c",&ch);
    
    while(ch == 'Y' || ch == 'y')
    {
        printf("Enter next value: ");
        scanf("%d",&n);
        
        New = (struct node *)malloc(sizeof(struct node));
        
        New -> data = n;
        New -> add = NULL;
        temp -> add = New;
        temp = New;
        
        printf("To enter more element Press 'Y': ");
        scanf(" %c",&ch);
    }
} // end of Create function


void Insert() // start of Insert function
{
   int n, position, i = 1, count  = 0;
   
   if(start == NULL)
   {
       printf("list not created, Please create list first\n");
   }
   else
   {
       printf("Enter a value: ");
       scanf("%d",&n);
       
       New  = (struct node *)malloc(sizeof(struct node));
       
       New -> data = n;
       New -> add = NULL;
       
       printf("Enter the position for node insertion: ");
       scanf("%d",&position);
       
       if(position == 1)
       {
           New -> add = start;
           start = New;
       }
       else
       {
           temp = start;
           
           while(temp != NULL)
           {
               count++;
               temp = temp -> add;
           }
           
           if(position > count + 1)
           {
               printf("invalid position, it can not be more than %d\n",(count+1));
           }
           else if (position == count + 1)
           {
               temp = start;
               while(temp -> add != NULL)
               {
                   temp = temp -> add;
               }
               temp -> add = New;
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
              prev -> add = New;
              New -> add = next;
           }
       }
   }
} // end of Insert function


void Delete()  // start of Delete function
{
   int position, count = 0, i = 1;
   
   if(start == NULL)
   {
       printf("List not created, create a list first\n");
   }
   else
   {
       printf("Enter a position: ");
       scanf("%d",&position);
       
       if(position == 1)
       {
           temp = start;
           start = start -> add;
           printf("Deleted element is: %d",temp -> data);
           free(temp);
       }
       else
       {
           temp = start;
           while(temp != NULL)
           {
               count++;
               temp = temp -> add;
           }
           
           if(position > count && position <= 0)
           {
               printf("invalid position, it can't be more than %d\n",count);
           }
           else if( position == count)
           {
               next = start;
               while(next -> add != NULL)
               {
                   prev = next;
                   next = next -> add;
               }
               printf("Deleted element is: %d", next -> data);
               free(next);
               prev -> add = NULL;
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
               printf("Deleted element is: %d",temp -> data);
               free(temp);
               prev -> add = next;
           }
       }
       
   }
}   // end of Delete function

void Display()    // start of Display function
{
   temp = start;
   if(temp == NULL)
   {
       printf("List is not created, Please created list first\n");
   }
   else
   {
       while(temp != NULL)
       {
           printf("%d\t",temp->data);
           temp = temp->add;
       }
   }
}    // end of Delete function


void Reverse() // start of Reverse funtion
{
    prev = NULL;
    temp = start;
    next = start;
    
    if(start == NULL)
    {
        printf("List is not created, Please create list first\n");
    }
    else
    {
        prev = NULL;
        temp = start;
        next = start;
        while(temp != NULL)
        {
            next = next -> add;
            temp -> add = prev;
            prev = temp;
            temp = next;
        }
        start = prev;
    }   
} // end of Reverse function

void minElement() // start of minElement function
{   
    if(start == NULL)
    {
        printf("List is not created, first create list...........\n");
    }
    else
    {
        int min = start->data;
        temp = start;
        while(temp != NULL)
        {
            if(min > temp -> data)
            {
                min = temp -> data;
            }
            temp = temp -> add;
        }
         printf("Minimum element in linked list is: %d\n",min);
    }
} // end of minElement function


void maxElement()  // start of maxElement function
{
    if(start == NULL)
    {
        printf("List is not created, first create list...........\n");
    }
    else
    {
        int max = start -> data;
        temp = start;
    
        while(temp != NULL)
        {
            if(max < temp -> data)
            {
                max = temp -> data;
            }
            temp = temp -> add;
        }
        printf("Maximum element is linked list is: %d\n",max);
    }
}

void ElementSearch()
{
    int key , f = 0;
    
    if(start == NULL)
    {
        printf("List is not created, first create list...........\n");
    }
    else
    {
        
        printf("Enter element to search: ");
        scanf("%d",&key);
        
        temp = start;
        while(temp != NULL)
        {
            if(key != temp -> data)
            {
               temp = temp -> add;
            }
            else
            {
                f = 1;
                break;
            }
        }
    }
    
    if (f == 0)
    {
        printf("Key not found,searching is unsuccessfull\n");
    }
    else
    {
        printf("Key is found,seraching is successfull");    
    }
}


