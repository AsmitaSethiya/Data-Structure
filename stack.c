// Stack :  Stack is a non-linear data structure,Stack works on the principal of LIFO (Last In First Out). Stack has only one end , called "TOP OF STACK"(top) .In stack, insetion and deletion done only one end(from the top).  


#include<stdio.h>   //header file include

#define Maxsize 10    // macro
int stack[Maxsize], top = -1;   

// decalation of function
void Push();
void Pop();
void Display();

void main()
{
    int choice;
    
    do
    {
        printf("\n***********************STACK OPERATION*****************************\n");
        printf("Enter 1 for performing Push operaion on Stack\n");
        printf("Enter 2 for performing Pop operaion on Stack\n");
        printf("Enter 3 for performing Display operaion on Stack\n");
        printf("Enter 4 for performing exit operaion\n\n");
        
        printf("Enter your choice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                Push();
                break;
            case 2:
                Pop();
                break;
            case 3:
                Display();
                break;
            case 4:
                break;
            default:
                printf("!!! WARNING !!! invalid choice, please enter valid choice\n");
        }
    }
    while(choice!=4);
}

// Push operation
void Push()
{
    int n;
    
    if (top == Maxsize - 1)    // checking overflow condition (overflow: stack is not empty)
    {
        printf("Stack is overflow\n");
    }
    else    // performing push operation
    {
        printf("Enter value : ");
        scanf("%d\n",&n);
        top++;
        stack[top] = n;
    }
}

// Pop operation
void Pop()
{
    if(top == -1)
    {
        printf("Stack is underflow\n"); // checking underflow condition (underflow: stack is empty)
    }
    else
    {
        printf("Deleted value is %d\n: ", stack[top]);
        top--;
    }
}

// Display operation
void Display()
{
    int i;
    if(top == -1)
    {
        printf("Stack is underflow\n");
    }
    else
    {
        for(i = 0; i < top; i++)
        {
            printf("%d\t\n",stack[i]);
        }
    }
}
