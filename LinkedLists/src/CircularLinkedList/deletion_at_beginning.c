#include <stdio.h>
#include <stdlib.h>


typedef struct Node_t
{
    int value;
    int key;
    struct Node_t *next;
} Node;

Node *head = NULL;
Node *current = NULL;

Node *delete_at_beginning();
void insert_at_beginning(int value, int key);
void print_list();

int main()
{
    print_list();
    
    insert_at_beginning(1, 0);
    insert_at_beginning(2, 1);
    insert_at_beginning(3, 2);

    print_list();

    return 0;
}

Node *delete_at_beginning()
{

}

void insert_at_beginning(int value, int key)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        perror("[Error]: Memory allocation failure! Exiting... \n");
        exit(EXIT_FAILURE);
    }

    new_node->value = value;
    new_node->key = key;

    if (head == NULL)
    {
        head = new_node;
        head->next = head;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
}

void print_list()
{
    Node *current = head;

    printf("[");

    if (head != NULL)
    {
        while (current->next != current)
        {
            printf("(%d, %d), ", current->value, current->key);
            current = current->next;
        }
    }

    printf("] \n");
}