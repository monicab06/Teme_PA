#include <stdio.h>

int graf[15][15];

void incarcaCSV(char* numeFisier) {

    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
            if (i == j)
                graf[i][j] = 0;
            else
                graf[i][j] = 999999;


    FILE *f = fopen(numeFisier, "r");
    int u, v, cost;

    while (fscanf(f, "%d,%d,%d", &u, &v, &cost) != EOF)
        graf[u][v] = cost;

    fclose(f);
}

void afiseaza(int parinte[], int dist[], int dest) {
    int drum[15];
    int pasi = 0;
    
    int curent = dest;
    while (curent != -1) {
        drum[pasi] = curent;
        pasi = pasi + 1;
        curent = parinte[curent];
    }

    printf("Drum: ");
    for(int i = pasi - 1; i >= 0; i--)
        printf("%d ", drum[i]);
    
    printf("\nMuchii: ");
    for(int i = pasi - 1; i > 0; i--) {
        int u = drum[i];
        int v = drum[i-1];
        printf("%d ", graf[u][v]);
    }
    
    printf("\nCost total: %d\n\n", dist[dest]);
}

void dijkstra(int start, int dest) {
    int dist[15];
    int vizitat[15];
    int parinte[15];

    for(int i = 0; i < 15; i++) { 
        dist[i] = 999999; 
        vizitat[i] = 0;
        parinte[i] = -1; 
    }
    
    dist[start] = 0;

    for(int pas = 0; pas < 14; pas++) {
        int min = 999999;
        int u = -1;


        for(int i = 0; i < 15; i++)
            if (vizitat[i] == 0 && dist[i] < min) { 
                min = dist[i]; 
                u = i; 
            }
                
        if (u == -1)
            break;
        
        vizitat[u] = 1;

        for(int v = 0; v < 15; v++)
            if (vizitat[v] == 0 && graf[u][v] != 999999)
                if (dist[u] + graf[u][v] < dist[v]) {
                    dist[v] = dist[u] + graf[u][v];
                    parinte[v] = u;
                }
    }
    
    printf("Dijkstra:\n");
    afiseaza(parinte, dist, dest);
}

void bellman_ford(int start, int dest) {
    int dist[15];
    int parinte[15];

    for(int i = 0; i < 15; i++) { 
        dist[i] = 999999; 
        parinte[i] = -1; 
    }
    
    dist[start] = 0;

    for(int pas = 0; pas < 14; pas++)
        for(int u = 0; u < 15; u++)
            for(int v = 0; v < 15; v++)
                if (graf[u][v] != 999999 && dist[u] != 999999)
                    if (dist[u] + graf[u][v] < dist[v]) {
                        dist[v] = dist[u] + graf[u][v];
                        parinte[v] = u;
                    }
    
    printf("Bellman-Ford:\n");
    afiseaza(parinte, dist, dest);
}

int main() {
    printf("input_vechi.cv\n");
    incarcaCSV("input_vechi.csv");
    dijkstra(2, 14);
    bellman_ford(2, 14);

    printf("input.csv\n");
    incarcaCSV("input.csv");
    dijkstra(2, 14);
    bellman_ford(2, 14);

    return 0;
}