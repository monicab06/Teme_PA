#include <stdio.h>

void hanoi(int nr_disc, char sursa, char dest, char aux) {

    if (nr_disc == 1) {
        printf("Mutam discul 1 de pe tija %c pe tija %c\n", sursa, dest);
        return;
    }
    
    hanoi(nr_disc - 1, sursa, aux, dest);

    printf("Mutam discul %d de pe tija %c pe tija %c\n", nr_disc, sursa, dest);

    hanoi(nr_disc - 1, aux, dest, sursa);
}

int main() {
    int discuri = 6;
    hanoi(discuri, 'A', 'C', 'B'); 
    return 0;
}

