#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t
{
    int value;
    struct Node_t* next;
} Node;


Node* head = NULL;
Node* current = NULL;


void insert_at_index(int data, int index);
void print_list();

int main()
{
    print_list();

    insert_at_index(1, 0);
    insert_at_index(2, 1);
    insert_at_index(3, 2);
    insert_at_index(4, 0);

    print_list();

    return 0;
}

void insert_at_index(int data, int index)
{
    current = head;

    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        perror("[Error]: Memory allocation failure! Exiting... \n");
        exit(EXIT_FAILURE);
    }

    new_node->value = data;

    if (index == 0)
    {
        new_node->next = current;
        head = new_node;
        return; 
    }

    Node* prev = current;
    current = current->next;

    int current_index = 1;

    while (current_index != index)
    {  
        if (current == NULL)
        {
            printf("No such index. \n");
            return;
        }

        current_index++;
        prev = current;
        current = current->next;
    }

    prev->next = new_node;
    new_node->next = current;

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
