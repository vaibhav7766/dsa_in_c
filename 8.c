#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int V;             // Number of vertices
    struct Node** adj; // Array of linked lists
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adj = (struct Node**)malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adj[dest];
    graph->adj[dest] = newNode;
}

void deleteEdge(struct Graph* graph, int src, int dest) {
    struct Node* current = graph->adj[src];
    if (current != NULL && current->data == dest) {
        graph->adj[src] = current->next;
        free(current);
        return;
    }

    while (current != NULL) {
        struct Node* next = current->next;
        if (next != NULL && next->data == dest) {
            current->next = next->next;
            free(next);
            return;
        }
        current = current->next;
    }
}

void displayGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        struct Node* current = graph->adj[i];
        printf("Adjacency list of vertex %d: ", i);
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int V = 5; // Number of vertices
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    printf("Initial graph:\n");
    displayGraph(graph);

    deleteEdge(graph, 0, 1);

    printf("\nGraph after deleting an edge:\n");
    displayGraph(graph);

    return 0;
}
