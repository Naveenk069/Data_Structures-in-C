#include <stdio.h>
#include <stdlib.h>

struct data {
    int p;
    int value;
};

int front = -1; rear = -1;
int size = 5;
struct data pqueue[5];

int isfull()
{
    if(rear == size - 1)
        return 1;
    else
        return 0;
}

int isempty()
{
    if(front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(struct data temp) {
    if (isfull()) {
        printf("Queue is full\n");
    } else if (isempty()) {
        front++;
        rear++;
        pqueue[front].p = temp.p;
        pqueue[front].value = temp.value;
    } else {
        int t = rear;
        while (t >= 0 && pqueue[t].p > temp.p) {
            pqueue[t + 1].p = pqueue[t].p;
            pqueue[t + 1].value = pqueue[t].value;
            t--;
        }
        pqueue[t + 1].p = temp.p;
        pqueue[t + 1].value = temp.value;
        rear++;
    }
}

void dequeue() {
    if (isempty()) {
        printf("Queue is empty\n");
    } else if (front == rear) {
        printf("%d", pqueue[front].value);
        front = -1;
        rear = -1;
    } else {
        printf("%d", pqueue[front].value);
        front++;
    }
}

void display() {
    if (isempty()) {
        printf("Queue is empty\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", pqueue[i].value);
        }
        printf("\n");
    }
}

int main() {
    int option, in = 0;
    struct data temp;

    while (1) {
        printf("\nQueue Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter the option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the priority : ");
                scanf("%d", &temp.p);
                printf("Enter the value : ");
                scanf("%d", &temp.value);
                enqueue(temp);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
        }
    }

    return 0;
}
