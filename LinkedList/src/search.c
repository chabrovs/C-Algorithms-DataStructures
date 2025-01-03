#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node_t
{
    char *value;
    struct Node_t *next;
} Node;

Node *head = NULL;
Node *current = NULL;

bool search(char *value);
void insert_at_end(char *data);
void print_list();

int main()
{
    print_list();

    insert_at_end("abc");
    insert_at_end("def");
    insert_at_end("ghi");

    print_list();

    char *to_search = "def";

    bool search_result = search(to_search);

    printf("Seach result for \"%s\" = %d \n", to_search, search_result);

    return 0;
}

bool search(char *value)
{
    current = head;

    while (current != NULL)
    {
        if (current->value == value)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

void insert_at_end(char *data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
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
}

void print_list()
{
    current = head;

    printf("[");

    while (current != NULL)
    {
        printf("\"%s\", ", current->value);
        current = current->next;
    }

    printf("] \n");
}