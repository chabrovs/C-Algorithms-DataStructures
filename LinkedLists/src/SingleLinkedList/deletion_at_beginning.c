#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t
{
    int value;
    struct Node_t* next;
} Node;

Node* head = NULL;
Node* current = NULL;

void insert_at_beginning(int data);
void delete_at_beginning();
void print_list();

int main()
{
    insert_at_beginning(1);
    insert_at_beginning(2);

    print_list();

    delete_at_beginning();

    print_list();

    return 0;
}

void insert_at_beginning(int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        perror("[Error]: Memory allocation failure! Exiting.., \n");
        exit(EXIT_FAILURE);
    }

    new_node->value = data;
    new_node->next = head;
    head = new_node;

    return;
}

void delete_at_beginning()
{
    if (head == NULL)
    {
        printf("Linked list is empty! \n");
        return;
    }
    current = head;
    head = current->next;
    free(current);
    
    return;
}

void print_list()
{
    current = head;

    printf("[");

    while (current != NULL)
    {
        printf("%d, ", current->value);
        current = current->next;
    }

    printf("] \n");
}