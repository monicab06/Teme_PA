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
    for (int i = 0; i < N; i++){
        graph->head[i] = NULL;
    }

    for (int i = 0; i < n; i++){
        int src = edges[i].src;
        int dest = edges[i].dest;

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->dest = dest;

        newNode->next = graph->head[src];

        graph->head[src] = newNode;
    }
    return graph;
}

void printGraph(struct Graph* graph){
    int i;
    for(i = 0; i< N; i++)
    {
        struct Node* ptr = graph->head[i];
        while(ptr != NULL)
        {
            printf("%d - > %d", i, ptr->dest);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void DFS(struct Graph* graph, int vertex, int visited[]){
    
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* adjList = graph->head[vertex];

    while(adjList != NULL) {
        int connectedVertex = adjList->dest;

        if(!visited[connectedVertex])
            DFS(graph, connectedVertex, visited);

        adjList = adjList->next;
    }
}

void BFS(struct Graph* graph, int startVertex)
{
    int visited[N] = {0};
    int queue[100];
    int front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while(front < rear){
        int currentVertex = queue[front++];
        printf("%d", currentVertex);

        struct Node* temp = graph->head[currentVertex];

        while(temp != NULL){
            int adjVertex = temp ->dest;

            if(!visited[adjVertex]){
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

int main(void)
{
    struct Edge edges[] =
    {
        {0, 1}, {1, 0}, 
        {0, 2}, {2, 0}, 
        {1, 3}, {3, 1}, 
        {1, 4}, {4, 1}, 
        {2, 4}, {4, 2}, 
        {4, 5}, {5, 4}
    };

    int n = sizeof(edges)/sizeof(edges[0]);

    struct Graph *graph = createGraph(edges, n);

    printf("Structura grafului (Lista de Adiacenta):\n");
    printGraph(graph);
    printf("\n");

    //rularea DFS
    int visitedDFS[N] = {0};
    printf("Traversare DFS ");
    DFS(graph, 0, visitedDFS);
    printf("\n");

    // rularea BFS
    printf("Traversare BFS ");
    BFS(graph, 0);
    printf("\n");

    return 0;
}