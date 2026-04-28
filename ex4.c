#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
    for (int i = 0; i < N; i++) graph->head[i] = NULL;

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

int getMinMaxDistance(struct Graph* graph, int nodeData[]) {
    int min_val = INT_MAX;
    int max_val = INT_MIN;

    for (int i = 0; i < N; i++) {
        if (nodeData[i] < min_val) min_val = nodeData[i];
        if (nodeData[i] > max_val) max_val = nodeData[i];
    }

    if (min_val == max_val) return 0;

    int distances[N];
    int queue[100];
    int front = 0, rear = 0;

    for (int i = 0; i < N; i++) {
        distances[i] = -1;
    }

    for (int i = 0; i < N; i++) {
        if (nodeData[i] == min_val) {
            queue[rear++] = i;
            distances[i] = 0;
        }
    }

    while (front < rear) {
        int current = queue[front++];

        if (nodeData[current] == max_val) {
            return distances[current];
        }

        struct Node* temp = graph->head[current];
        while (temp != NULL) {
            int neighbor = temp->dest;

            if (distances[neighbor] == -1) {
                distances[neighbor] = distances[current] + 1;
                queue[rear++] = neighbor;
            }
            temp = temp->next;
        }
    }

    return -1; 
}

int main(void) {
    // 0 - 1 - 2
    // |       |
    // 3 - 4 - 5
    struct Edge edges[] = {
        {0, 1}, {1, 0},
        {1, 2}, {2, 1},
        {0, 3}, {3, 0},
        {3, 4}, {4, 3},
        {4, 5}, {5, 4},
        {2, 5}, {5, 2}
    };
    int n = sizeof(edges) / sizeof(edges[0]);
    struct Graph* graph = createGraph(edges, n);

    int nodeData[N] = {10, 50, 90, 40, 60, 10};

    printf("Datele nodurilor: \n");
    for(int i = 0; i < N; i++) {
        printf("Nodul %d are valoarea %d\n", i, nodeData[i]);
    }

    int dist = getMinMaxDistance(graph, nodeData);

    if (dist != -1) {
        printf("Cea mai mica distanta dintre un nod MIN si unul MAX este: %d pasi.\n", dist);
    } else {
        printf("Nu exista drum intre nodul minim si cel maxim.\n");
    }

    return 0;
}