#include <stdio.h>

int verificare(int matrice[9][9], int *r, int *c) {
    for (*r = 0; *r < 9; (*r)++) {
        for (*c = 0; *c < 9; (*c)++) {
            if (matrice[*r][*c] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int is_safe(int matrice[9][9], int rand, int coloana, int numar) {

    for (int i = 0; i < 9; i++) {
        if (matrice[rand][i] == numar) {
            return 0;
        }
    }

    for (int i = 0; i < 9; i++) {
        if (matrice[i][coloana] == numar) {
            return 0;
        }
    }

    int start_rand = rand - (rand % 3);
    int start_col = coloana - (coloana % 3);
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrice[start_rand + i][start_col + j] == numar) {
                return 0;
            }
        }
    }

    return 1;
}

int solve(int matrice[9][9]) {
    int rand, coloana;

    if (verificare(matrice, &rand, &coloana) == 0) {
        return 1;
    }

    for (int numar = 1; numar <= 9; numar++) {
        
        if (is_safe(matrice, rand, coloana, numar) == 1) {

            matrice[rand][coloana] = numar;
            if (solve(matrice) == 1) {
                return 1;
            }
            matrice[rand][coloana] = 0;
        }
    }

    return 0;
}

void afisare(int matrice[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

int main() {
    
    int sudoku[9][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 8},
        {1, 8, 0, 0, 0, 2, 3, 0, 0},
        {0, 6, 0, 0, 5, 7, 0, 0, 1},
        {0, 7, 0, 9, 6, 0, 0, 0, 0},
        {0, 9, 0, 7, 0, 4, 0, 1, 0},
        {0, 0, 0, 0, 8, 1, 0, 4, 0},
        {6, 0, 0, 2, 4, 0, 0, 8, 0},
        {0, 0, 4, 5, 0, 0, 0, 9, 3},
        {5, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    if (solve(sudoku) == 1) {
        printf("Rezolvare:\n");
        afisare(sudoku);
    } else {
        printf("Nu exista solutie");
    }

    return 0;
}