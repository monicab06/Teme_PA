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

// Funcția de creare a grafului
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

int hasPath(struct Graph* graph, int current, int target, int visited[]) {
    if (current == target) {
        return 1;
    }
    visited[current] = 1;

    struct Node* temp = graph->head[current];

    while (temp != NULL) {
        int neighbor = temp->dest;

        if (!visited[neighbor]) {

            if (hasPath(graph, neighbor, target, visited) == 1) {
                return 1;
            }
        }
        temp = temp->next;
    }

    return 0;
}

int checkPath(struct Graph* graph, int start, int target) {
    int visited[N] = {0}; // Inițializăm un array curat de vizite cu 0
    return hasPath(graph, start, target, visited);
}

int main(void) {

    struct Edge edges[] = {
        {0, 1}, {0, 2}, 
        {1, 3}, 
        {2, 4}, 
        {4, 5}
    };

    int n = sizeof(edges) / sizeof(edges[0]);
    struct Graph* graph = createGraph(edges, n);

    int start = 0, target1 = 5, target2 = 3;

    if (checkPath(graph, start, target1)) {
        printf("Exista un drum intre %d si %d.\n", start, target1);
    } else {
        printf("NU exista drum intre %d si %d.\n", start, target1);
    }

    if (checkPath(graph, 3, target1)) {
        printf("Exista un drum intre 3 si %d.\n", target1);
    } else {
        printf("NU exista drum intre 3 si %d.\n", target1);
    }

    return 0;
}