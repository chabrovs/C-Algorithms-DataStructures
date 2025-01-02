#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t {
    int value;
    struct Node_t* next;
} Node;

Node* head = NULL;
Node* current = NULL;

void insert_at_end(int data);
void delete_at_end();
void print_list();

int main()
{
    insert_at_end(1);    
    insert_at_end(2);    
    insert_at_end(3);    

    print_list();

    delete_at_end();

    print_list();

    return 0;
}

void insert_at_end(int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        perror("[Error]: Memory allocation failure! Exiting... \n");
        exit(EXIT_FAILURE);
    }

    new_node->value = data;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
        
        return;
    }

    current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = new_node;

    return;
}

void delete_at_end()
{
    if (head == NULL)
    {
        printf("Linked list is empty! \n");
        return;
    }
    if (head->next == NULL)
    {
        printf("HERE HEAD=%d\n", head->value);
        free(head);
        head = NULL;
        return;
    }
    
    current = head;

    while (current->next->next != NULL)
    {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

void print_list()
{
    current = head;

    printf("[");

    while (current != NULL)
    {
        printf("%d, ", (*current).value);
        current = (*current).next;
    }

    printf("] \n");
    
}