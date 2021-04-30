#include<stdio.h>

#define Maxsize 10
int Q[Maxsize], front = 0, rear = -1;

// function decalation
void Insert();
void Delete();
void Display();

void main() //main function start
{
    int choice;
    do
    {
        printf("***********************QUEUE OPERATION**********************\n");
        
        printf("Enter 1 for perform Insert operation on Queue\n");
        
        printf("Enter 2 for perform Delete operation on Queue\n");
        
        printf("Enter 3 for perform Display operation on Queue\n");
        
        printf("Enter 4 for exit\n");
        
        printf("Enter your choice to perform operation on Queue: ");
        
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                Insert();
                break;
            case 2:
                Delete();
                break;
            case 3:
                Display();
                break;
            case 4:
                break;
            default:
                printf("!! WARNING !! Invalid choice, please enter valid choice.....\n ");
        }
    }
    while(choice!=4);
}// end of main function

void Insert()  // start insert() function
{
    int n;
    
    if(rear == Maxsize-1)  // checking for Overflow condition Queue 
    {
        printf("Queue Overflow\n"); 
    }
    else
    {
        printf("Enter a value: ");
        scanf("%d",&n);
        
        rear++;
        Q[rear] = n;
    }
} // end of Insert function

void Delete() // start of Delete function
{
    if(rear < front)   // checking for underflow condition in Queue 
    {
        printf("Queue underflow\n");
    }
    else
    {
        printf("Deleted value is:  %d\n", Q[front]);
        front++;
    }
} // end of Delete function

void Display() // start of Display() function
{
    if(rear < front)  // checking for underflow condition in Queue
    {
        printf("Queue underflow\n");
    }
    else
    {
        for(int i = front; i <= rear; i++)
        {
            printf("%d\t\n",Q[i]);
        }
    }
}  // end of Display() function 
