#include<stdio.h>
struct node
{
    int data;
    struct node* link;
};
struct node* rear = NULL;
struct node* front = NULL;
struct node* temp;

struct node* new_node(int val)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = val;
    new->link = NULL;
    return new;
}

void enqueue(int n)
{
    if(front == NULL)
    {
        front = new_node(n);
        rear = front;
    }
    else
    {
        temp = new_node(n);
        rear->link = temp;
        rear = temp;
    }
}

void dequeue()
{
    if(front == NULL)
        printf("Queue is empty\n");
    else
    {
        printf("%d\n",front->data);
        front = front->link;
        if(front == NULL)
            rear = NULL;
    }
}

void display()
{
    if(front == NULL)
        printf("Queue is empty\n");
    else
    {
        struct node* current;
        current = front;
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
        printf("\nQueue Menu :\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter option : ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                printf("Enter the value : ");
                scanf("%d",&n);
                enqueue(n);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
        }
    }
}
