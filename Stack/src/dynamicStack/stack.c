#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Stack_t
{
    int *array;
    size_t capacity; // Current allocated capacity
    size_t size;     // Number of elements in the Stack
} Stack;

Stack *createStack(size_t initialCapacity);
int push(Stack *stack, int value);
int pop(Stack *stack, int *value);
int peek(Stack *stack, int *value);
int isEmpty(Stack *stack);
int getSize(Stack *stack);
int getCapacity(Stack *stack);
void printStack(Stack *stack);
void freeStack(Stack *stack);

int main()
{
    Stack *myStack = createStack(4);

    if (myStack == NULL)
    {
        fprintf(stderr, "Failed to create stack\n");
        return 1;
    }

    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);
    push(myStack, 40);

    int poppedValue;
    if (pop(myStack, &poppedValue))
    {
        printf("Popped value: %d \n", poppedValue);
    }

    int peekedValue;
    if (peek(myStack, &peekedValue))
    {
        printf("Peeked value: %d \n", peekedValue);
    }

    printStack(myStack);

    freeStack(myStack);

    return 0;
}

Stack *createStack(size_t initialCapacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL)
    {
        return NULL;
    }

    stack->capacity = initialCapacity;
    stack->size = 0;
    stack->array = (int *)malloc(initialCapacity * sizeof(int));

    if (stack->array == NULL)
    {
        free(stack);
        return NULL;
    }

    return stack;
}

int push(Stack *stack, int value)
{
    if (stack->size == stack->capacity)
    {
        // double the capacity if the stack is full
        size_t newCapacity = stack->capacity * 2;
        int *newArray = (int *)realloc(stack->array, newCapacity * sizeof(int));

        if (newArray == NULL)
        {
            return 0;
        }

        stack->array = newArray;
        stack->capacity = newCapacity;
    }

    stack->array[stack->size++] = value;

    return 1;
}

int pop(Stack *stack, int *value)
{
    if (stack->size == 0)
    {
        return 0;
    }

    if (value != NULL)
    {
        *value = stack->array[--stack->size];
    }
    else
    {
        --stack->size;
    }

    return 1;
}

int peek(Stack *stack, int *value)
{
    if (stack->size == 0)
    {
        return 0;
    }

    if (value != NULL)
    {
        *value = stack->array[stack->size - 1];
    }

    return 1;
}

int isEmpty(Stack *stack)
{
    if (stack->size == 0)
    {
        return 1;
    }

    return 0;
}

int getSize(Stack *stack)
{
    return stack->size;
}

int getCapacity(Stack *stack)
{
    return stack->capacity;
}

void printStack(Stack *stack)
{
    for (int i = 0; i < stack->size; i++)
    {
        printf("Stack[%d] = %d \n", i, stack->array[i]);
    }
}

void freeStack(Stack *stack)
{
    if (stack != NULL)
    {
        free(stack->array);
        free(stack);
    }
}