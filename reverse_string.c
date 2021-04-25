#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 20

int top = -1;
char stack[MAX];
char pop();
void push(char);

int main()
{
        char str[20];
        unsigned int i;
        
        printf("Enter the string : " );
        gets(str);
        
        int len = strlen(str);
        
        /*Push characters of the string str on the stack */
        for(i = 0; i < len; i++)
        {
             push(str[i]);
        }
                
        /*Pop characters from the stack and store in string str */
        for(i = 0; i < len; i++)
        {
            str[i]=pop();
        }
                
        printf("\nReversed string is : ");
        puts(str);

        return 0;

}/*End of main()*/

void push(char item)
{
        if(top == (MAX-1))
        {
                printf("\nStack Overflow\n");
                return;
        }
        else
        {
            stack[++top] =item;   
        }
       
}/*End of push()*/

char pop()
{
        if(top == -1)
        {
                printf("\nStack Underflow\n");
                exit(1);
        }
        else
        {
            return stack[top--];    
        }
        
}/*End of pop()*/
