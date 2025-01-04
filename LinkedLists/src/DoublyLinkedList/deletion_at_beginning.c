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

void delete_at_beginning();
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

    delete_at_beginning();
    delete_at_beginning();
    delete_at_beginning();

    print_list();



    return 0;
}

void delete_at_beginning()
{
    if (head == NULL)
    {
        printf("[Warning]: cannot remove items from an empty Linked List! \n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        tail = NULL;
        return;
    }
    current = head;
    current->next->prev = NULL;
    head = current->next;
    free(current);
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