#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode; // Point to itself in a circular list
        *head = newNode;
    } else {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        newNode->next = *head;
        last->next = newNode;
        *head = newNode;
    }
    printf("Node with data %d inserted at the beginning.\n", data);
}

// Function to insert a node at a specified position in the circular linked list
void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position. Position should be >= 1.\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    int count = 1;

    while (count < position - 1 && current->next != *head) {
        current = current->next;
        count++;
    }

    if (count < position - 1) {
        printf("Position exceeds the length of the list.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
    printf("Node with data %d inserted at position %d.\n", data, position);
}

// Function to delete a node from a specified position in the circular linked list
void deleteFromPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position. Position should be >= 1.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;
    int count = 0;

    do {
        count++;
        prev = temp;
        temp = temp->next;
    } while (temp != *head && count < position);

    if (count < position) {
        printf("Position exceeds the length of the list.\n");
        return;
    }

    prev->next = temp->next;

    if (*head == temp) {
        *head = temp->next;
    }

    free(temp);
    printf("Node at position %d deleted.\n", position);
}

// Function to search for an element and delete it from the circular linked list
void searchAndDelete(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    do {
        if (temp->data == data) {
            if (prev == NULL) {
                // Deleting the first node
                *head = temp->next;
                if (*head == temp) {
                    *head = NULL; // List becomes empty
                }
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Node with data %d deleted.\n", data);
            return;
        }

        prev = temp;
        temp = temp->next;
    } while (temp != *head);

    printf("Node with data %d not found in the list.\n", data);
}

// Function to reverse the circular linked list
void reverse(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to reverse.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;
    struct Node* next = NULL;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != *head);

    (*head)->next = prev;
    *head = prev;
    printf("List reversed.\n");
}

// Function to display the circular linked list
void display(struct Node* head) {
    struct Node* current = head;
    
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Circular Linked List: ");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("%d -> ...\n", current->data); // Print ellipsis to indicate circular nature
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nCircular Linked List Menu:\n");
        printf("1. Create\n");
        printf("2. Insert at any position\n");
        printf("3. Delete from any position\n");
        printf("4. Search the element and delete\n");
        printf("5. Reverse\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(&head, position);
                break;
            case 4:
                printf("Enter data to search and delete: ");
                scanf("%d", &data);
                searchAndDelete(&head, data);
                break;
            case 5:
                reverse(&head);
                display(head);
                break;
            case 6:
                display(head);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}