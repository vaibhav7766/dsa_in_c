#include <stdio.h>
#include <stdlib.h>

// Define a structure for a doubly linked list node
struct node {
    char name[20];
    long long int rollno;
    int age;
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
    printf("Enter roll no., name, age: ");
    scanf("%lld %s %d", &newnode->rollno, newnode->name, &newnode->age);
    
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
        // Print the roll no., name, and age of each node
        printf("%lld %s %d\n", temp->rollno, temp->name, temp->age);
        temp = temp->next;
    }
}

int main() {
    int choice = 1;
    while (choice == 1) {
        // Create a new node and add it to the list
        create();
        printf("Do you want to continue? (0/1): ");
        scanf("%d", &choice);
    }

    // Display the contents of the doubly linked list
    display();

    return 0;
}
