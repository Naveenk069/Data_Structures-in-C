#include <stdio.h>
int stack[5];
int size = 5;
int top = -1;

int is_full()
{
    if(top==(size-1))
        return 1;
    else
        return 0;
}

int is_empty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

void push(int temp){
    if(is_full())
        printf("Stack is full\n");
    else
        stack[++top]=temp;
}

void pop(){

    if(is_empty())
      printf("Stack is empty\n");
    else
    {

      stack[top] = 0;
      top--;

    }
}

void peek()
{   if(is_empty())
        printf("Array is empty\n");
    else
        printf("%d\n",stack[top]);
}

void display ()
{
    if(top==-1)
        printf("No elements to display");
    else
        for(int i=top;i>=0;i--)
            printf("%d ",stack[i]);
    printf("\n");
}
int main()
{
   int option,in=0;

   while(1)
    {
        printf("\nStack Menu\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");


        printf("Enter the option : ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                printf("Enter the no. : ");
                scanf("%d",&in);
                push(in);
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
    return 0;
}
