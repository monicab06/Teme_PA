#include <stdio.h>
#include <stdlib.h>

#define N 6 

struct Graph {
    struct Node* head[N];
};

struct Node {
    int dest;
    struct Node* next;
};

struct Edge {
    int src, dest;
};

struct Graph* createGraph(struct Edge edges[], int n) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    for (int i = 0; i < N; i++) {
        graph->head[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->dest = dest;
        newNode->next = graph->head[src];
        graph->head[src] = newNode;
    }
    return graph;
}

int detectCycleUtil(struct Graph* graph, int current, int parent, int visited[]) {

    visited[current] = 1;

    struct Node* temp = graph->head[current];

    while (temp != NULL) {
        int neighbor = temp->dest;

        if (!visited[neighbor]) {

            if (detectCycleUtil(graph, neighbor, current, visited)) {
                return 1;
            }
        }
        else if (neighbor != parent) 
            return 1;

        temp = temp->next;
    }

    return 0; 
}

int hasCycle(struct Graph* graph) {
    int visited[N] = {0}; 

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {

            if (detectCycleUtil(graph, i, -1, visited)) {
                return 1;
            }
        }
    }
    return 0;
}

int main(void) {
    struct Edge edges1[] = {
        {0, 1}, {1, 0}, 
        {1, 2}, {2, 1}, 
        {2, 0}, {0, 2}  
    };
    int n1 = sizeof(edges1) / sizeof(edges1[0]);
    struct Graph* graph1 = createGraph(edges1, n1);

    if (hasCycle(graph1)) {
        printf("Graful 1 contine cel putin un ciclu.\n");
    } else {
        printf("Graful 1 NU contine cicluri.\n");
    }

    struct Edge edges2[] = {
        {0, 1}, {1, 0}, 
        {1, 2}, {2, 1}, 
        {2, 3}, {3, 2}
    };
    int n2 = sizeof(edges2) / sizeof(edges2[0]);
    struct Graph* graph2 = createGraph(edges2, n2);

    if (hasCycle(graph2)) {
        printf("Graful 2 contine cel putin un ciclu.\n");
    } else {
        printf("Graful 2 NU contine cicluri.\n");
    }

    return 0;
}