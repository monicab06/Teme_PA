#include <stdio.h>
#include <stdlib.h>

int grid[5][6];

void init() {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 6; j++)
            grid[i][j] = 0;

    grid[0][1] = 1;
    grid[2][1] = 1;
    grid[3][1] = 1;
    grid[2][3] = 1;
    grid[3][4] = 1;
    grid[4][4] = 1;
}

// functie euristica
int heuristic(int r, int c) {
    return abs(4 - r) + abs(5 - c); 
}

void afiseaza(int parinte[], int dest) {
    int drum[30];
    int pasi = 0;
    int curent = dest;


    while (curent != -1) {
        drum[pasi] = curent;
        pasi = pasi + 1;
        curent = parinte[curent];
    }

    printf("Ruta optima A*:\n");
    for (int i = pasi - 1; i >= 0; i--) {

        int r = drum[i] / 6;
        int c = drum[i] % 6;
        
        printf("(%d,%d) ", r, c);
        if (i > 0) printf("-> ");
    }
    printf("\n\nTotal pasi parcursi: %d\n", pasi - 1);
}

void a_star() {
    int g[30];
    int vizitat[30];
    int parinte[30];

    // initializare
    for (int i = 0; i < 30; i++) {
        g[i] = 999999;
        vizitat[i] = 0;
        parinte[i] = -1;
    }

    int start = 0;
    int dest = 29;
    g[start] = 0;


    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};


    for (int pas = 0; pas < 30; pas++) {
        int min_f = 999999;
        int u = -1;


        for (int i = 0; i < 30; i++)
            if (vizitat[i] == 0 && g[i] != 999999) {
                int r = i / 6;
                int c = i % 6;
                int f = g[i] + heuristic(r, c);
                
                if (f < min_f) {
                    min_f = f;
                    u = i;
                }
            }

        if (u == -1 || u == dest) 
            break;
            
        vizitat[u] = 1;

        int r = u / 6;
        int c = u % 6;


        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < 5 && nc >= 0 && nc < 6)

                if (grid[nr][nc] == 0) {
                    int v = nr * 6 + nc;
                    
                    if (vizitat[v] == 0)
                    
                        if (g[u] + 1 < g[v]) {
                            g[v] = g[u] + 1;
                            parinte[v] = u;
                        }
                }
        }
    }

    afiseaza(parinte, dest);
}

int main() {

    init();
    a_star();
    return 0;

}