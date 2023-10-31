#include <stdio.h>
#include <stdlib.h>

// Define a structure for a doubly linked list node
struct node {
    char aadhar[12];
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
    
    // Input Aadhar number for the new node
    printf("Enter Aadhar number: ");
    scanf("%s", newnode->aadhar);
    
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

// Function to display the contents of the doubly linked list
void display() {
    struct node *temp;
    temp = head;
    while (temp != NULL) {
        // Print the Aadhar number of each node
        printf("%s ", temp->aadhar);
        temp = temp->next;
    }
}

// Function to insert a new node at the beginning of the list
void insert_at_beginning(struct node **ptr, struct node *newnode) {
    (*ptr)->prev = newnode;
    newnode->next = *ptr;
    *ptr = newnode;
}

// Function to insert a new node in between the list
void insert_in_btw(struct node **ptr, struct node *newnode, int pos, int count) {
    int i = 1;
    struct node *temp = *ptr;
    
    if (pos > count) {
        printf("Invalid position");
    } else if (pos == 1) {
        // Insert at the beginning
        insert_at_beginning(ptr, newnode);
    } else {
        while (i < pos - 2) {
            temp = temp->next;
            i++;
        }
        // Insert in between
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;
    }
}

int main() {
    struct node *newnode;
    int choice = 1, pos, count = 0;

    while (choice == 1) {
        // Create a new node and add it to the list
        create();
        printf("Do you want to continue? (0/1): ");
        scanf("%d", &choice);
        count++;
    }

    // Create a new node for insertion
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter new data: ");
    scanf("%s", newnode->aadhar);
    printf("Enter position: ");
    scanf("%d", &pos);
    newnode->prev = NULL;
    newnode->next = NULL;

    // Insert the new node in between
    insert_in_btw(&head, newnode, pos, count);

    // Display the contents of the doubly linked list
    display();

    return 0;
}
