#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for an employee node
struct emp {
    char name[50];
    char pan[11];
    struct emp* next;
};

// Function to create a new employee node with provided name and PAN
struct emp* createemp(char* name, char* pan) {
    struct emp* newemp = (struct emp*)malloc(sizeof(struct emp));
    strcpy(newemp->name, name);
    strcpy(newemp->pan, pan);
    newemp->next = NULL;
    return newemp;
}

int main() {
    // Create employee nodes and initialize them with name and PAN
    struct emp* emp1 = createemp("Tejas", "103810FSJS");
    struct emp* emp2 = createemp("Suyash", "JDJS192801");
    struct emp* emp3 = createemp("Jay", "39NSHIA192");
    struct emp* emp4 = createemp("Vaibhav", "DSJK612981");
    struct emp* emp5 = createemp("Vedant", "JDIOAS1201");

    // Connect the employee nodes to form a linked list
    emp1->next = emp2;
    emp2->next = emp3;
    emp3->next = emp4;


    emp5->next = emp1; //inserting employee 5 at the beginning

    // Traverse the linked list and print employee details
    struct emp* current = emp5; // Start from emp5
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("PAN: %s\n", current->pan);
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