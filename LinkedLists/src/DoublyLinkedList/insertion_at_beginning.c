#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t
{
    int value;
    struct Node_t *prev;
    struct Node_t *next;
} Node;

Node *head = NULL;
Node *tail = NULL;
Node *current = NULL;

void insert_at_beginning(int value);
void print_list();
void print_list_backwards();

int main()
{
    print_list();

    insert_at_beginning(1);
    insert_at_beginning(2);
    insert_at_beginning(3);

    print_list();
    print_list_backwards();

    return 0;
}

void insert_at_beginning(int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        perror("[Error]: Memory allocation failure! Exiting... \n");
        exit(EXIT_FAILURE);
    }

    new_node->value = value;

    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
        return;
    }

    current = head;

    current->prev = new_node;
    new_node->next = current;

    head = new_node;
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

void print_list_backwards()
{
    current = tail;

    printf("[");

    while (current != NULL)
    {
        printf("%d, ", current->value);
        current = current->prev;
    }

    printf("] \n");
}