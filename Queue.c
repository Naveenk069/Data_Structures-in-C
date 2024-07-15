#include<stdio.h>
#include<conio.h>
#include <ctype.h>
#include <string.h>
#define size 3
int arr[size];
int front=-1;int rear=-1;
void dequeue(){
    if (front==-1 && rear==-1){
            printf("Queue is empty\n");

    }
    else if(front==rear){
        arr[front]=0;
        front=-1;rear=-1;
    }
    else{
        printf("%d",arr[front]);
        arr[front] = 0;
        front++;
    }
}
void enqueue(int temp){
if(rear==size-1){
    printf("Queue is  full\n");
}
else if(front==-1 && rear==-1){
    front++;rear++;
    arr[front]=temp;
}
else{
    rear++;
    arr[rear]=temp;
}
}
void display(){
    if(front==-1 && rear ==-1){
        printf("Queue is empty\n");
    }
    else{
    for(int i=front;i<=rear;i++){
        printf("%d ",arr[i]);
    }
    }
}

int main()
{
   int option,elem=0;

   while(1)
    {
        printf("\nQueue Menu\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter the option : ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                printf("Enter the no. : ");
                scanf("%d",&elem);
                enqueue(elem);
                break;
            case 2:
                dequeue();
                break;

            case 3:
                display();
                printf("\n");
                break;
            case 4:
                exit(0);
        }

    }

}
