#include <stdio.h>

void mananca_bomboane(int numar_bomboane) {

    if (numar_bomboane == 0) {
        printf("Sfarsit. Cutia s-a golit si nu mai avem bomboane.\n");
        return;
    }

    printf("Am mancat o bomboana. Au mai ramas %d in cutie.\n", numar_bomboane - 1);

    mananca_bomboane(numar_bomboane - 1);
}

int main() {
    printf("Avem o cutie cu 5 bomboane.\n");
    mananca_bomboane(5);
    return 0;
}
