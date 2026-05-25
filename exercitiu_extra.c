#include <stdio.h>

int harta[8][8];

char* orase[] = {
    "Timisoara", "Cluj-Napoca", "Sibiu", "Iasi", 
    "Brasov", "Craiova", "Bucuresti", "Constanta"
};

void init() {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (i == j)
                harta[i][j] = 0;
            else
                harta[i][j] = 999999;
}


void adauga(int u, int v, int km) {
    harta[u][v] = km;
    harta[v][u] = km;
}

void afiseaza(int parinte[], int dist[], int dest) {
    int drum[8];
    int pasi = 0;
    int curent = dest;
    
    while (curent != -1) {
        drum[pasi] = curent;
        pasi = pasi + 1;
        curent = parinte[curent];
    }

    printf("Ruta: ");
    for (int i = pasi - 1; i >= 0; i--) {
        printf("%s", orase[drum[i]]);
        if (i > 0) printf(" -> ");
    }
    
    printf("\nTotal: %d km\n\n", dist[dest]);
}

void dijkstra(int start, int dest) {
    int dist[8], vizitat[8], parinte[8];

    for (int i = 0; i < 8; i++) {
        dist[i] = 999999;
        vizitat[i] = 0;
        parinte[i] = -1;
    }
    dist[start] = 0;

    for (int pas = 0; pas < 7; pas++) {
        int min = 999999;
        int u = -1;
        
        // cautam minimul nevizitat
        for (int i = 0; i < 8; i++)
            if (vizitat[i] == 0 && dist[i] < min) { 
                min = dist[i]; 
                u = i; 
            }
                
        if (u == -1) break;
        vizitat[u] = 1;

        // actualizam vecinii
        for (int v = 0; v < 8; v++)
            if (vizitat[v] == 0 && harta[u][v] != 999999)
                if (dist[u] + harta[u][v] < dist[v]) {
                    dist[v] = dist[u] + harta[u][v];
                    parinte[v] = u;
                }
    }
    
    afiseaza(parinte, dist, dest);
}

int main() {
    init();
    
    adauga(0, 1, 319); adauga(0, 2, 271); adauga(0, 5, 336);
    adauga(1, 2, 176); adauga(1, 3, 480);
    adauga(2, 3, 460); adauga(2, 4, 120); adauga(2, 6, 300);
    adauga(3, 4, 300); adauga(3, 6, 550);
    adauga(4, 6, 170); adauga(4, 7, 400);
    adauga(5, 6, 235);
    adauga(6, 7, 250);

    printf("1. Timisoara -> Constanta\n");
    dijkstra(0, 7);

    printf("2. Craiova -> Iasi\n");
    dijkstra(5, 3);

    printf("3. Constanta -> Cluj-Napoca\n");
    dijkstra(7, 1);

    return 0;
}