#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for a node in a singly linked list
struct node {
    int a; // Data of the node
    struct node* next; // Pointer to the next node
};

// Function to insert a new node at the end of the linked list
void insert_at_end(struct node** ptr, struct node* newnode) {
    newnode->next = NULL;
    if (*ptr == NULL) {
        *ptr = newnode; // If the list is empty, make the new node the head
    }
    else {
        struct node* temp = *ptr;
        while (temp->next != NULL) {
            temp = temp->next; // Traverse the list to find the last node
        }
        temp->next = newnode; // Link the new node to the last node
    }
}

// Function to delete the first node from the beginning of the linked list
void delete_from_start(struct node** ptr) {
    if (*ptr == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct node* temp = *ptr;
    *ptr = (*ptr)->next; // Update the head to point to the second node
    free(temp); // Free the memory of the deleted node
}

// Function to delete the last node from the end of the linked list
void delete_from_end(struct node** ptr) {
    if (*ptr == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct node* temp = *ptr;
    struct node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next; // Traverse the list to find the last node and its previous node
    }
    if (prev == NULL) {
        *ptr = NULL; // If there was only one node, set the head to NULL
    }
    else {
        prev->next = NULL; // Update the previous node to remove the last node
    }
    free(temp); // Free the memory of the deleted node
}

// Function to delete a node from a specific position in the linked list
void delete_in_btw(struct node** ptr, int pos, int count) {
    if (*ptr == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if (pos < 1 || pos > count) {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1) {
        delete_from_start(ptr); // If deleting the first node, call the delete_from_start function
        return;
    }

    struct node* temp = *ptr;
    struct node* prev = NULL;
    int i = 1;

    while (i < pos) {
        prev = temp;
        temp = temp->next; // Traverse the list to find the node to delete and its previous node
        i++;
    }

    prev->next = temp->next; // Update the previous node to skip the node to delete
    free(temp); // Free the memory of the deleted node
}

// Function to print the elements of the linked list
void printll(struct node** ptr) {
    struct node* travel = *ptr;
    while (travel != NULL) {
        printf("%d ", travel->a); // Print the data of each node
        travel = travel->next; // Move to the next node
    }
}

int main() {
    struct node* head = NULL;
    int pos;

    printf("Enter heights of 10 students: ");
    for (int i = 0; i < 10; i++) {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &temp->a);
        insert_at_end(&head, temp); // Insert each height at the end of the linked list
    }

    printf("Original linked list: \n");
    printll(&head); // Print the original linked list

    printf("\nDeletion from a specific position.\nEnter index to delete: ");
    scanf("%d", &pos);
    delete_in_btw(&head, pos, 10); // Delete a node from the specified position
    printll(&head); // Print the updated linked list

    printf("\nDeleting from the end: \n");
    delete_from_end(&head); // Delete the last node
    printll(&head); // Print the updated linked list

    printf("\nDeleting from the beginning: \n");
    delete_from_start(&head); // Delete the first node
    printll(&head); // Print the updated linked list

    return 0;
}