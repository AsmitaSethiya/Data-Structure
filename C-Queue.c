#include<stdio.h>

#define Maxsize 5  // macro

int Q[Maxsize], front = -1, rear = -1;

// Decalaration of function
void enqueue();
void dequeue();
void Display();

void main() // main function start
{
    int choice;
    
    do
    {
    
    printf("*******************CIRCULAR QUEUE*******************\n");
    
    printf("Enter 1 to perform Enqueue operation on C-Queue\n");
    
    printf("Enter 2 to perform Dequeue operation on C-Queue\n");
    
    printf("Enter 3 to perform Display operation on C-Queue\n");
    
    printf("Enter 4 for exit\n");
    
    printf("Enter your choice: ");
    scanf("%d",&choice);
    
    switch(choice)
    {
        case 1:
            enqueue(); // function calling.....
            break;
        case 2:
            dequeue(); // function calling.....
            break;
        case 3:
            Display(); // function calling......
            break;
        case 4:
            break;
        default:
            printf("!!WARNING!!, invalid choice, please enter valid choice\n");
    }
    
    }
    
    while(choice!=4);
} // end of main function


// definition of enqueue function 
void enqueue() // start of enqueue function
{
    int x;
    printf("Enter a value: ");
    scanf("%d",&x);
    
    if(front == -1 && rear == -1)
    {
        front  = rear = 0;
        Q[rear] = x;
    }
    else if((rear+1)%Maxsize == front) // checking for overflow conditon
    {
        printf("C-Queue is overflow\n");
    }
    else
    {
        rear = (rear + 1) % Maxsize;
        Q[rear]  = x;
    }
} // end of enqueue function


//definition of dequeue function
void dequeue() // start of dequeue function
{
    if(front == -1 && rear == -1) // checking for underflow conditon
    {
        printf("C-Queue is underflow\n"); 
    }
    else if(front == rear)
    {
        printf("%d\n",Q[front]);
        front = rear = -1;
    }
    else
    {
        printf("%d\n",Q[front]);
        front = (front+1)%Maxsize;
    }
} // end of dequeue function


// definition of Display function
void Display() // start of Display function
{
    if(front == -1 && rear == -1) // checking for underflow conditon
    {
        printf("C-Queue is underflow\n");
    }
    else 
    {
        int i = front;
        
        printf("Your element in C-Queue is: \n");
        
        while(i != rear)
        {
            printf("%d\n",Q[i]);
            
            i = (i + 1) % Maxsize;
        }
        
        printf("%d\n",Q[i]);
    }
} // end of Display function
