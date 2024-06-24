#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 4

struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    struct Node* adjListArray[MAX_VERTICES];
};

struct Graph* createGraph() {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));

    for (int i = 0; i < MAX_VERTICES; i++)
        graph->adjListArray[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = graph->adjListArray[src];
    graph->adjListArray[src] = newNode;

    // Add edge from dest to src (for undirected graph)
    newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->dest = src;
    newNode->next = graph->adjListArray[dest];
    graph->adjListArray[dest] = newNode;
}

void printGraph(struct Graph* graph) {
    for (int v = 0; v < MAX_VERTICES; v++) {
        struct Node* temp = graph->adjListArray[v];
        printf("Adjacency list of vertex %d\n", v);
        while (temp) {
            printf(" -> %d", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Graph* graph = createGraph();
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);

    printGraph(graph);

    return 0;
}
