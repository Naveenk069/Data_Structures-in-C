#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char arr[]) {
    int i, operand1, operand2, result;
    for (i = 0; arr[i] != '\0'; i++) {
        if (isdigit(arr[i])) {
            push(arr[i]-'0');
        } else {
            operand2 = pop();
            operand1 = pop();
            switch (arr[i]) {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator encountered: %c\n", arr[i]);
                    exit(EXIT_FAILURE);
            }
        }
    }
    result = pop();
    return result;
}

int main() {
    char arr[MAX_SIZE] = {NULL};
    int choice, result;

    while(1) {
        printf("Menu:\n");
        printf("1. Enter postfix expression\n");
        printf("2. Evaluate postfix expression\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter postfix expression: ");
                scanf("%s",arr);
                break;
            case 2:
                if(arr[0]!='\0') {
                    result = evaluatePostfix(arr);
                    printf("Result: %d\n", result);
                    break;
                }
                else
                    printf("No expression given\n");
                    break;
            case 3:
                printf("Exiting program\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
