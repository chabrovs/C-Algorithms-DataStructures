/*
Simple fixed size Stack implementation based on an array.
*/

#include <stdio.h>

int MAXSIZE = 8;
int stack[8];
int top = -1;

int isEmpty();
int isFull();
int peek();
int pop();
void push(int value);

int main()
{
    push(1);
    push(2);
    push(3);

    printf("peek value: %d \n", peek());

    printf("isEmpty: %d \n", isEmpty());

    int popped_value = pop();

    printf("popped value: %d \n", popped_value);

    pop();
    pop();

    printf("isEmpty: %d \n", isEmpty());

    return 0;
}

int isEmpty()
{
    return (top == -1) ? 1 : 0;
}

int isFull()
{
    return (top == MAXSIZE) ? 1 : 0;
}

int peek()
{
    if (isEmpty())
    {
        printf("Stack is empty!");
    }

    return stack[top];
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack is empty!");
    }

    int value = stack[top];
    top--;

    return value;
}

void push(int value)
{
    if (isFull())
    {
        printf("Stack is full!");
    }

    top++;
    stack[top] = value;
}