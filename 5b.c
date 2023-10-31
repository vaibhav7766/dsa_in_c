#include <stdio.h>
#include <stdlib.h>

// Define a structure for a doubly linked list node
struct node {
    char name[20];
    char pan[10];
    struct node *next;
    struct node *prev;
};

// Initialize pointers for the head and tail of the doubly linked list
struct node *head = NULL, *tail = NULL;

// Function to create a new node and add it to the doubly linked list
void create() {
    struct node *temp;
    struct node *newnode = NULL;
    newnode = (struct node *)malloc(sizeof(struct node));
    
    // Input data for the new node
    printf("Enter name, pan: ");
    scanf("%s %s", newnode->name, newnode->pan);
    
    // Initialize the previous and next pointers of the new node
    newnode->prev = NULL;
    newnode->next = NULL;
    
    // If the list is empty, set the new node as both the head and tail
    if (head == NULL) {
        head = temp = newnode;
        tail = newnode;
    } else {
        // Add the new node to the end of the list
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
        tail = newnode;
    }
}

// Function to insert a new node at the beginning of the list
void insert_at_beginning(struct node **ptr, struct node *newnode) {
    (*ptr)->prev = newnode;
    newnode->next = *ptr;
    *ptr = newnode;
}

// Function to display the contents of the doubly linked list
void display() {
    struct node *temp;
    temp = head;
    while (temp != NULL) {
        // Print the name and PAN of each node
        printf("%s %s\n", temp->name, temp->pan);
        temp = temp->next;
    }
}

int main() {
    struct node *newnode;
    int choice = 1;

    while (choice == 1) {
        // Create a new node and add it to the list
        create();
        printf("Do you want to continue? (0/1): ");
        scanf("%d", &choice);
    }
    
    printf("List before insertion at the beginning:\n");
    display();

    // Create a new node and insert it at the beginning of the list
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter details of the new employee:\n");
    printf("Enter name, PAN: ");
    scanf("%s %s", newnode->name, newnode->pan);
    insert_at_beginning(&head, newnode);

    printf("List after insertion at the beginning:\n");
    display();

    return 0;
}
