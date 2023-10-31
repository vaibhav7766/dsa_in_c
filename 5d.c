#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in a doubly linked list
struct node {
    int data;             // Data of the node
    struct node* prev;    // Pointer to the previous node
    struct node* next;    // Pointer to the next node
};

// Function to insert a new node at the end of the doubly linked list
void insert_at_end(struct node** head_ptr, struct node** tail_ptr, struct node* newnode) {
    newnode->next = NULL;
    if (*head_ptr == NULL) {
        *head_ptr = newnode; // If the list is empty, make the new node the head
        newnode->prev = NULL;
        *tail_ptr = newnode; // Update the tail pointer
    }
    else {
        struct node* temp = *tail_ptr;
        temp->next = newnode; // Link the current tail node to the new node
        newnode->prev = temp; // Set the previous pointer of the new node
        *tail_ptr = newnode; // Update the tail pointer to the new node
    }
}

// Function to delete the first node from the beginning of the doubly linked list
void delete_from_start(struct node** head_ptr, struct node** tail_ptr) {
    if (*head_ptr == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct node* temp = *head_ptr;
    *head_ptr = (*head_ptr)->next; // Update the head to point to the second node
    if (*head_ptr != NULL) {
        (*head_ptr)->prev = NULL; // Set the previous pointer of the new head to NULL
    }
    else {
        *tail_ptr = NULL; // If there was only one node, set the tail to NULL
    }
    free(temp); // Free the memory of the deleted node
}

// Function to delete the last node from the end of the doubly linked list
void delete_from_end(struct node** head_ptr, struct node** tail_ptr) {
    if (*tail_ptr == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct node* temp = *tail_ptr;
    if (temp->prev != NULL) {
        temp->prev->next = NULL; // Update the previous node to remove the last node
        *tail_ptr = temp->prev; // Update the tail pointer to the previous node
    }
    else {
        *head_ptr = NULL; // If there was only one node, set the head to NULL
        *tail_ptr = NULL; // Also set the tail to NULL
    }
    free(temp); // Free the memory of the deleted node
}

// Function to delete a node from a specific position in the doubly linked list
void delete_in_btw(struct node** head_ptr, struct node** tail_ptr, int pos, int count) {
    if (*head_ptr == NULL || *tail_ptr == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if (pos < 1 || pos > count) {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1) {
        delete_from_start(head_ptr, tail_ptr); // If deleting the first node, call the delete_from_start function
        return;
    }

    struct node* temp = *head_ptr;
    int i = 1;

    while (i < pos) {
        temp = temp->next; // Traverse the list to find the node to delete
        i++;
    }

    temp->prev->next = temp->next; // Update the previous node to skip the node to delete
    if (temp->next != NULL) {
        temp->next->prev = temp->prev; // Update the next node's previous pointer
    }
    else {
        *tail_ptr = temp->prev; // If deleting the last node, update the tail pointer
    }
    free(temp); // Free the memory of the deleted node
}

// Function to print the elements of the doubly linked list
void printll(struct node** ptr) {
    struct node* travel = *ptr;
    while (travel != NULL) {
        printf("%d ", travel->data); // Print the data of each node
        travel = travel->next; // Move to the next node
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    struct node* tail = NULL; // Initialize tail pointer
    int pos;

    printf("Enter heights of 10 students: ");
    for (int i = 0; i < 10; i++) {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &temp->data);
        insert_at_end(&head, &tail, temp); // Insert each height at the end of the doubly linked list
    }

    printf("Original doubly linked list: \n");
    printll(&head); // Print the original doubly linked list

    printf("\nDeletion from a specific position.\nEnter index to delete: ");
    scanf("%d", &pos);
    delete_in_btw(&head, &tail, pos, 10); // Delete a node from the specified position
    printll(&head); // Print the updated doubly linked list

    printf("\nDeleting from the end: \n");
    delete_from_end(&head, &tail); // Delete the last node
    printll(&head); // Print the updated doubly linked list

    printf("\nDeleting from the beginning: \n");
    delete_from_start(&head, &tail); // Delete the first node
    printll(&head); // Print the updated doubly linked list

    return 0;
}