#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t
{
    int value;
    struct Node_t *prev;
    struct Node_t *next;
} Node;

Node *tail = NULL;
Node *head = NULL;
Node *current = NULL;

void delete_at_end();
Node *pop();
void insert_at_end(int value);
void print_list();

int main()
{
    print_list();

    insert_at_end(1);
    insert_at_end(2);
    insert_at_end(3);

    print_list();

    delete_at_end();

    print_list();

    Node* node = pop();

    printf("Popped Node value = %d \n", node->value);

    free(node);

    return 0;
}

void delete_at_end()
{
    /*
    Delete the last node at the end of the Linked List freeing the memory.

    Time complexity: O(1).
    */
    if (head == NULL)
    {
        printf("[Error]: Connot delete from an empty Linked List. \n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        tail = NULL;
        head = NULL;
        return;
    }

    Node *to_delete = tail;
    tail = to_delete->prev;
    tail->next = NULL;
    free(to_delete);
}

Node *pop()
{
    /*
    Return the last element from the list and remove this element from the list
    without freeing the memory.

    Time Complexity: O(1);
    */
    if (head == NULL)
    {
        printf("[Error]: Cannot pop from an empty list. \n");
    }

    Node *temp = tail;

    if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        tail->prev->next = NULL;
    }

    tail = tail->prev;

    return temp;
}

void insert_at_end(int value)
{
    /*
    Create a new Node and insert it at the end (tail) of the Linked List.

    Time Complexity: O(1).
    */
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        perror("[Error]: Memory allocation failure! Exiting... \n");
        exit(EXIT_FAILURE);
    }

    new_node->value = value;

    if (head == NULL)
    {
        tail = new_node;
        head = new_node;
        return;
    }

    current = tail;

    new_node->prev = current;
    current->next = new_node;

    tail = new_node;
}

void print_list()
{
    /*
    Print all value in the Linked List's Nodes in order.

    Time complexity: O(n);
    Where n is the number of Nodes in the Linked List.
    */
    current = head;

    printf("[");

    while (current != NULL)
    {
        printf("%d, ", current->value);
        current = current->next;
    }

    printf("] \n");
}
