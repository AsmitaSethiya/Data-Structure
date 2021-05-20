#include<stdio.h>
#include<malloc.h>

struct node
{
    struct node *ladd;
    struct node *radd;
    int data;
};

struct node *root = NULL;

struct node * Create(struct node *p, int n);
void inorder(struct node *p);
void preorder(struct node *p);
void postorder(struct node *p);

void main()
{
    int choice, n;
    
    do
    {
        printf("\n**************BINARY SEARCH TREE******************\n");
        
        printf("Press 1 for Create Tree\n");
        
        printf("Press 2 for Inorder Trevarsal\n");
        
        printf("Press 3 for Preorder Traversal\n");
        
        printf("Press 4 for Postorder Traversal\n");
        
        printf("Press 5 for Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("Enter value, Press 0 to quit: ");
                scanf("%d", &n);
                while(n != 0)
                {
                    root = Create(root, n);
                    printf("Enter next value: ");
                    scanf("%d", &n);
                }
            case 2:
                inorder(root);
                break;
            case 3:
                preorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice, Please enter valid choice.........'n");
        }
        
    } 
    while(choice != 5);
}


struct node * Create(struct node *p, int n)
{
    if(p == NULL)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p -> ladd = NULL;
        p -> data = n;
        p -> radd = NULL;
    }
    else 
    {
        if(n < p -> data)
        {
            p -> ladd = Create(p -> ladd, n);
        }
        else if(n > p -> data)
        {
            p -> radd = Create(p -> radd, n);
        }
        else
        {
            printf("Duplicate data not allowed\n");
        }
    }
    return(p);
}

void inorder(struct node *p)
{
    if(p != NULL)
    {
        inorder(p -> ladd);
        printf("%d\t", p -> data);
        inorder(p -> radd);
    }
}

void preorder(struct node *p)
{
    if(p != NULL)
    {
        printf("%d\t", p -> data);
        preorder(p -> ladd);
        preorder(p -> radd);
    }
}

void postorder(struct node *p)
{
    if(p != NULL)
    {
        postorder(p -> ladd);
        postorder(p -> radd);
        printf("%d\t", p -> data);
    }
}
