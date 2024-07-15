#include<stdio.h>

struct node
{
    int data;
    struct node* link;
};
struct node* top = NULL;
struct node* temp;

struct node* new_node(int val)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = val;
    new->link = NULL;
    return new;
}

void push(int n)
{
    if(top == NULL)
        top = new_node(n);
    else
    {
        temp = new_node(n);
        temp->link = top;
        top = temp;
    }
}

void pop()
{
    if(top == NULL)
        printf("Stack is empty\n");
    else
    {
        printf("%d\n",top->data);
        top = top->link;
    }
}

void peek()
{
    if(top == NULL)
        printf("Stack is empty\n");
    else
        printf("%d\n",top->data);
}

void display()
{
    if(top == NULL)
        printf("Stack is empty\n");
    else
    {
        struct node* current;
        current = top;
        while(current != NULL)
        {
            printf("%d ",current->data);
            current = current->link;
        }
        printf("\n");
    }
}

int main()
{
    int option;
    int n;
    while(1)
    {
        printf("\nStack Menu :\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter option : ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                printf("Enter value : ");
                scanf("%d",&n);
                push(n);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
        }
    }
}
