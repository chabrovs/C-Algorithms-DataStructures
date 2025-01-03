#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t
{
    int data;
    struct Node_t *next;
} Node;

Node *head = NULL;
Node *current = NULL;

void print_linked_list();
void insert_at_beginning(int data);

int main()
{
    while (1)
    {
        int value;

        printf("Insert value: ");
        scanf("%d", &value);

        insert_at_beginning(value);

        printf("Current linked list: ");
        print_linked_list();
    }

    return 0;
}

void print_linked_list()
{

    Node *current = head;

    printf("[");

    while (current != NULL)
    {
        printf("%d, ", current->data);
        current = current->next;
    }

    printf("] \n");
}

void insert_at_beginning(int data)
{

    Node *linked_list = (Node *)malloc(sizeof(Node));

    if (linked_list == NULL)
    {
        perror("[ERROR]: Failed to malloc! Exiting... \n");
        exit(EXIT_FAILURE);
    }

    linked_list->data = data;
    linked_list->next = head;

    head = linked_list;
}