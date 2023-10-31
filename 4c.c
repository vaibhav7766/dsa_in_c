#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for an employee node
struct emp {
    char aadhar[10];
    struct emp* next;
};

// Function to create a new employee node with the provided Aadhar number
struct emp* createemp(char* aadhar) {
    struct emp* newemp = (struct emp*)malloc(sizeof(struct emp));
    strcpy(newemp->aadhar, aadhar);
    newemp->next = NULL;
    return newemp;
}

int main() {
    // Create employee nodes and initialize them with Aadhar numbers
    struct emp* emp1 = createemp("1028019310");
    struct emp* emp2 = createemp("3293190292");
    struct emp* emp3 = createemp("3293789138");
    struct emp* emp4 = createemp("1321921327");
    struct emp* emp5 = createemp("3623893016");

    // Connect the employee nodes to form a linked list
    emp1->next = emp2;
    emp2->next = emp3;
    emp3->next = emp4;

    emp5->next = emp3; // Link emp5 to emp3
    emp2->next = emp5; // Link emp2 to emp5

    // Traverse the linked list and print Aadhar numbers
    struct emp* current = emp1; // Start from emp1
    while (current != NULL) {
        printf("%s\n", current->aadhar);
        current = current->next;
    }

    // Free memory allocated for employee nodes
    free(emp1);
    free(emp2);
    free(emp3);
    free(emp4);
    free(emp5);

    return 0;
}