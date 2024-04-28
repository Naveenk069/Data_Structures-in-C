#include <stdio.h>
int top=-1;
int size=5;
int arr[5];

int isfull()
{
    if(top==size-1)
        return 1;
    else
        return 0;
}

int isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}


void insert_front(int temp)
{
    if(isfull())
        printf("Array is full\n");
    else
    {
        for(int i=top; i>=0; i--)
            arr[i+1] = arr[i];
        top++;
        arr[0] = temp;
    }

}

void insert_back(int temp)
{
    if(isfull())
        printf("Array is full\n");
    else
        {
            top++;
            arr[top] = temp;
        }
}

void del_front()
{
    if(isempty())
        printf("Array is empty\n");
    else
    {
        for(int i=0; i<=top; i++)
            arr[i] = arr[i+1];
        top--;
    }
}

void del_back()
{
    if(isempty())
        printf("Array is empty\n");
    else
        {
            arr[top] = 0;
            top--;
        }

}

void display ()
{
    if(isempty())
        printf("Array is empty");
    else
    {
        for(int i=0;i<=top;i++)
        {
            printf("%d ",arr[i]);
        }
    }
    printf("\n");
}
int main()
{
   int option=0;
   int temp;
   while(1)
    {
        printf("\n1.Insert at front\n");
        printf("2.Insert at back\n");
        printf("3.Delete at front\n");
        printf("4.Delete at back\n");
        printf("5.Display\n");
        printf("6.Exit\n");

        printf("Enter the option : ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d",&temp);
                insert_front(temp);
                break;
            case 2:
                printf("Enter element: ");
                scanf("%d",&temp);
                insert_back(temp);
                break;
            case 3:
                del_front();
                break;
            case 4:
                del_back();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
        }



    }
    return 0;
}
