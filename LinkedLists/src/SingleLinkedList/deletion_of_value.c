#include <stdio.h>
#include <stdlib.h>

typedef struct Note_t
{
    int value;
    struct Note_t *next;
} Node;

Node *head = NULL;
Node *current = NULL;

void insert(int data);
void delete(int data);
void print_list();

int main()
{
    insert(1);
    insert(2);
    insert(4);

    print_list();

    delete(1);
    
    print_list();

    return 0;
}

void insert(int data)
{
    current = head;

    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        perror("[Error]: Memory allocation failure! Exiting... \n");
        exit(EXIT_FAILURE);
    }
    new_node->value = data;
    new_node->next = current;
    head = new_node;
}

void delete(int data)
{
    current = head;

    if (current->value == data)
    {
        head = current->next;
        free(current);
        return;
    }

    Node *prev = current;
    current = current->next;

    while (current != NULL)
    {
        if (current->value == data)
        {
            // Delete
            prev->next = current->next;
            free(current);
            return;
        }

        prev = current;
        current = current->next;
    }
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