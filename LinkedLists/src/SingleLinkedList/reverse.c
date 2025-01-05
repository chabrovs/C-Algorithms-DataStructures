#include <stdio.h>
#include <stdlib.h>


typedef struct Node_t
{
    int value;
    struct Node_t* next;
} Node;

Node* head = NULL;
Node* current = NULL;

void print_list();
void insert_at_end(int data);
void reverse_list();

int main()
{
    insert_at_end(1);
    insert_at_end(2);
    insert_at_end(3);

    print_list();

    reverse_list();

    print_list();


    return 0;
}

void reverse_list()
{
    Node* current = head, *prev = NULL, *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

void insert_at_end(int data)
{
    current = head;

    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        perror("[Error]: Memory allocation failure! Exiting... \n");
        exit(EXIT_FAILURE);
    }

    new_node->value = data;
    new_node->next = NULL;

    if (current == NULL)
    {
        head = new_node;
        return;
    }

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = new_node;

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