#include <stdio.h>
#include <stdlib.h>

typedef struct Note_t
{
    int value;
    struct Node_t *next;
} Node;

typedef struct Stack_t
{
    int size;
    Node *head;
    Node *top;
} Stack;

Stack *initStack(Node *head);
int push(Stack *stack, int value);
int pop(Stack *stack, int *value);
int peek(Stack *stack, int *value);
int isEmpty(Stack *stack);
void printStack(Stack *stack);

int main()
{
    Stack *myStack = initStack(NULL);

    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);

    printStack(myStack);

    int poppedValue;
    if (pop(myStack, &poppedValue))
    {
        printf("Popped value: %d \n", poppedValue);
    }

    printStack(myStack);

    if (isEmpty(myStack))
    {
        printf("The stack is empty; \n");
    }
    else
    {
        printf("The stack is not empty \n");
    }

    int peekedValue;
    if (peek(myStack, &peekedValue))
    {
        printf("Peeked value: %d \n", peekedValue);
    }

    return 0;
}

Stack *initStack(Node *head)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL)
    {
        perror("[Error]: Memory allocation failure! Exiting... \n");
        return 0;
    }

    stack->size = 0;
    stack->head = head;
    stack->top = head;

    return stack;
}

int push(Stack *stack, int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        perror("[Error]: Memory allocation failure! Exiting... \n");
        return 0;
    }

    new_node->value = value;
    new_node->next = NULL;

    Node *current = stack->head;

    if (stack->head == NULL)
    {
        stack->head = new_node;
        stack->top = new_node;
        stack->size++;
        return 1;
    }

    stack->size++;
    stack->top->next = new_node;
    stack->top = new_node;

    return 1;
}

int pop(Stack *stack, int *value)
{
    if (stack->top == NULL)
    {
        printf("The Stack is empty. \n");
        return 0;
    }

    *value = stack->top->value;

    // Delete the topmost element from the Stack

    Node *current = stack->head;

    while (current->next != stack->top)
    {
        current = current->next;
    }

    free(stack->top);
    current->next = NULL;
    stack->top = current;
    stack->size--;

    return 1;
}

int peek(Stack *stack, int *value)
{
    if (stack == NULL)
    {
        printf("The Stack is empty;");
        return 0;
    }

    *value = stack->top->value;

    return 1;
}

int isEmpty(Stack *stack)
{
    return (stack->head == NULL) ? 1 : 0;
}

void printStack(Stack *stack)
{
    Node *current = stack->head;

    if (current == NULL)
    {
        printf("The Stack is empty");
        return;
    }

    printf("[");
    while (current != NULL)
    {
        printf("%d, ", current->value);
        current = current->next;
    }

    printf("] \n");
}
