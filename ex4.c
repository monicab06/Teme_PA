#include <stdio.h>
#include <string.h>

typedef struct {
    char nume[20];
    float timp;
} Alergator;

void swap(Alergator *a, Alergator *b) {
    Alergator temp = *a;
    *a = *b;
    *b = temp;
}

void sorteazaAlergatori(Alergator a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j].timp > a[j + 1].timp) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

int main() {
    Alergator alergatori[] = {
        {"George", 10.22}, {"Ana", 8.75}, {"Mihai", 11.05},
        {"Elena", 9.40}, {"Radu", 10.01}, {"Cristina", 8.90},
        {"Alex", 9.15}, {"Andreea", 9.60}
    };
    
    int n = sizeof(alergatori) / sizeof(alergatori[0]);

    sorteazaAlergatori(alergatori, n);

    for(int i = 0; i < n; i++) 
        printf("Locul %d: %s\n", i + 1, alergatori[i].nume);

    return 0;
}