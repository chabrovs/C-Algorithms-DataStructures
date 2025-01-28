#include <stdio.h>
#include <stdlib.h>

// Node structure definition
typedef struct Node_t {
    int value;
    int key;
    struct Node_t *next;
} Node;

// Global pointers to manage the circular linked list
Node *head = NULL;

// Function declarations
void insert_at_beginning(int value, int key);
void print_list();

int main() {
    print_list(); // Should handle empty list case gracefully

    // Insert a few nodes at the beginning
    insert_at_beginning(1, 0);
    insert_at_beginning(2, 1);
    insert_at_beginning(3, 2);

    // Print the circular linked list
    print_list();

    return 0;
}

// Function to insert a node at the beginning of the circular linked list
void insert_at_beginning(int value, int key) {
    // Allocate memory for the new node
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("[Error]: Memory allocation failure! Exiting...\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the new node
    new_node->value = value;
    new_node->key = key;

    if (head == NULL) {
        // If the list is empty, point the new node to itself
        head = new_node;
        new_node->next = head;
    } else {
        // Traverse to the last node in the circular list
        Node *current = head;
        while (current->next != head) {
            current = current->next;
        }

        // Insert the new node at the beginning
        new_node->next = head;
        current->next = new_node; // Update the last node to point to the new head
        head = new_node;         // Update the head to the new node
    }
}

// Function to print the circular linked list
void print_list() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node *current = head;

    printf("[");
    do {
        // Print the current node
        printf("(%d, %d), ", current->value, current->key);
        current = current->next;
    } while (current != head);
    
    printf("]\n");
}
