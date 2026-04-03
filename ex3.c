#include <stdio.h>

void afisare(int vector[], int dimensiune, int i) {

    if (i == dimensiune)
        return;

    printf("%d ", vector[i]);
    afisare(vector, dimensiune, i + 1);
}

int main() {

    int numere[] = {10, 20, 30, 40, 50}, dimensiune = 5;
    afisare(numere, dimensiune, 0); 
    
    return 0;
}