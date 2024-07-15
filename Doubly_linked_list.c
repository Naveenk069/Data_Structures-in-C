#include<stdio.h>
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* head,* temp,* current;

struct node* new_node()
{
    struct node* new = (struct node*) malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d",&new->data);
    new->next = '\0';
    new->prev = '\0';
    return new;
}

void insert_front()
{
    if(head!=NULL)
    {
        temp = new_node();
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else
        head = new_node();
}

void insert_back()
{
    if(head == NULL)
        head = new_node();
    else
    {
        temp = new_node();
        current = head;
        while(current->next != NULL)
            current = current->next;
        current->next = temp;
        temp->prev = current;
    }
}
void delete_val(int n)
{
    if(head == NULL)
        printf("Empty\n");
    else if(head->data == n)
    {
        head = head->next;
        if(head == NULL)
            {}
        else
            head->prev = '\0';
    }
    else
    {
        current = head;
        while(current->next != NULL && current->next->data != n)
            current = current->next;
        if(current->next == NULL)
            printf("Not Found\n");
        else
        {
            current->next = current->next->next;
            if(current->next == NULL)
                {}
            else
                current->next->prev = current;
        }
    }
}

void delete_back()
{
    if(head == NULL)
        printf("Empty\n");
    else if(head->next == NULL)
        head = head->next;
    else
    {
        current = head;
        while(current->next->next != NULL)
            current = current->next;
        current->next = NULL;
    }
}

void display()
{
    if(head == NULL)
        printf("Empty");
    else
    {
        current = head;
        while(current != NULL)
        {
            printf("%d ",current->data);
            current = current->next;
        }
    }
    printf("\n");
}

int main()
{
    int option ;
    int n;
    while(1)
    {
        printf("\nDouble Linked List Menu :");
        printf("\n1.Insert front\n");
        printf("2.Delete value\n");
        printf("3.Insert at back\n");
        printf("4.Delete back\n");
        printf("5.Display\n");
        printf("6.Exit\n");
        printf("Enter the option : ");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            insert_front();
            break;
        case 2:
            printf("Enter the value : ");
            scanf("%d",&n);
            delete_val(n);
            break;
        case 3:
            insert_back();
            break;
        case 4:
            delete_back();
            break;
        case 5:
            display();
            break;
        case 6:
            return 0;
        }
    }
}
