#include <stdio.h>
#include <stdlib.h>


typedef struct Node_t
{
    int value;
    struct Node_t *next;
} Node;

typedef struct VisitedNode_t
{
    Node *node;
    struct VisitedNode_t *next;

} VisitedNode;


Node *head = NULL;
Node *current = NULL;


void insert_at_end(int value);
void insert_at_beginning(int value);
void print_list();
void free_linked_list();


int main()
{
    print_list();
    
    insert_at_end(1);
    insert_at_end(2);
    insert_at_end(3);

    // insert_at_beginning(1);
    // insert_at_beginning(2);
    // insert_at_beginning(3);

    print_list();

    free_linked_list();

    return 0;
}

void insert_at_end(int value)
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
        new_node->next = head;
        return;
    }

    Node *current = head;

    while (current->next != head)
    {
        current = current->next;
    }

    current->next = new_node;
    new_node->next = head;
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
        new_node->next = head;
        return;
    }

    new_node->next = head;
    head = new_node;
}


void print_list()
{
    if (head == NULL)
    {
        printf("The linked list is empty! \n");
        return;
    }

    // Step1. Tack all visited node by adding them to a new (visited_nodes) lined list
    // 1.1. Create a list of visited nodes.
    // 1. 2. Check if the current node is in the list of visited nodes 
    // 1. 3. If so break the loop as the cycle is detected, otherwise add the current node
    // at the beginning of the visited_nodes linked list so
    // to reduce the lookup complexity in case of a cycle detection.
    
    Node *current = head;
    VisitedNode *visited_head = NULL;
    
    printf("[ ");

    while (current != NULL)
    {

        VisitedNode *visited_current = visited_head;
        int already_visited = 0;
        while (visited_current != NULL)
        {
            if (visited_current->node == current) // Find whether or not the current node is in the visited nodes list.
            {
                already_visited = 1;
                break;
            }
            visited_current = visited_current->next;
        }

        if (already_visited == 1) {
            break; // The current node in visited list - break the loop.
        } 

        printf("%d, ", current->value); // The current node was not found in the visited nodes list, so print its value. 

        // Add the current node to the visited list
        VisitedNode *just_visited_node = (VisitedNode *)malloc(sizeof(VisitedNode));
        if (just_visited_node == NULL)
        {
            perror("[Error]: Memory allocation failure! Exiting.., \n");
            exit(EXIT_FAILURE);
        }

        just_visited_node->node = current;
        just_visited_node->next = visited_head; // Add at the beginning of the visited list. 
        visited_head = just_visited_node; // Do no forget the assign the just visited node to the head of the visited list -
        // (it is crucial when inserting new nodes at the beginning of the list).

        current = current->next; 
    }

    // Do not forget to free the visited list after printing all values in the main list.
    while (visited_head != NULL)
    {
        VisitedNode *tmp = visited_head;
        visited_head = visited_head->next;
        free(tmp);

    }
    printf("] \n");
}

void free_linked_list()
{
    if (head == NULL)
    {
        return;
    }

    Node *current = head, *tail = head;
    Node *next; 

    // Step 1. Break the loop (it is crucial)
    // 1.1. Identify the tail node.
    while (tail->next != head && tail->next != tail)
    {
        tail = tail->next;
    }
    // 1.2. Break the loop.
    tail->next = NULL;

    // Step 2. Iterate and free nodes. 
    while (current != NULL)
    {
        next = current->next;
        printf("freeing %d \n", current->value);
        free(current);
        current = next;
    }
}