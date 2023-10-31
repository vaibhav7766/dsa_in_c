#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for a student node
struct node {
    int rollno;
    char name[50];
    int age;
    struct node* next;
};

// Function to insert a new node at the end of the linked list
void insert_at_end(struct node** ptr, struct node* newnode) {
    newnode->next = NULL;
    if (*ptr == NULL) {
        // If the list is empty, set the new node as the head
        *ptr = newnode;
    }
    else {
        // Traverse the list to find the last node and link the new node
        struct node* temp = *ptr;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

int main() {
    struct node* head = NULL; // Initialize the head of the linked list
    struct node* travel; // Create a pointer to traverse the linked list
    int choice = 1; // Initialize the choice for user input
    int count = 0; // Initialize a counter for the number of nodes

    while (choice) {
        struct node* temp;
        struct node* newnode;
        newnode = (struct node*)malloc(sizeof(struct node)); // Allocate memory for a new node

        // Input student details
        printf("Enter rollno: ");
        scanf("%d", &newnode->rollno);
        printf("Enter name: ");
        scanf("%s", newnode->name);
        printf("Enter age: ");
        scanf("%d", &newnode->age);

        insert_at_end(&head, newnode); // Insert the new node at the end of the linked list

        printf("Do you wish to continue (0, 1): ");
        scanf("%d", &choice);
        count++;
    }

    // Traverse the linked list and print student details
    travel = head;
    while (travel != NULL) {
        printf("%d %s %d\n", travel->rollno, travel->name, travel->age);
        travel = travel->next;
    }

    return 0;
}