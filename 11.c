#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent the adjacency list of a vertex
struct List {
    struct Node* head;
};

// Structure to represent the graph
struct Graph {
    int numVertices;
    struct List* array;
};

// Function to create a new graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    graph->array = (struct List*)malloc((numVertices + 1) * sizeof(struct List));

    for (int i = 1; i <= numVertices; i++) {
        graph->array[i].head = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// Function to perform DFS traversal of the graph
void DFS(struct Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    struct Node* temp = graph->array[vertex].head;
    while (temp) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFS(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int numVertices = 6;
    struct Graph* graph = createGraph(numVertices);

    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 5);
    addEdge(graph, 5, 3);
    addEdge(graph, 5, 6);
    addEdge(graph, 6, 4);

    bool visited[numVertices + 1];
    for (int i = 1; i <= numVertices; i++) {
        visited[i] = false;
    }

    printf("Depth-First Search (DFS):\n");
    DFS(graph, 1, visited);

    return 0;
}