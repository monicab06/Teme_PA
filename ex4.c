#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nod {
    char cheie[50];
    char valoare[100];
    struct Nod* urmator;
};

struct Nod* tabela[31];

void init() {
    for (int i = 0; i < 31; i++)
        tabela[i] = NULL;
}

int hash(char* cheie) {
    int suma = 0;
    
    for (int i = 0; cheie[i] != '\0'; i++)
        suma = suma + cheie[i];
        
    return suma % 31;
}

void adauga(char* cheie, char* valoare) {
    int index = hash(cheie);

    struct Nod* nou = (struct Nod*)malloc(sizeof(struct Nod));
    strcpy(nou->cheie, cheie);
    strcpy(nou->valoare, valoare);
    
    nou->urmator = tabela[index];
    tabela[index] = nou;
    
    printf("Adaugam: %s -> %s\n", cheie, valoare);
}

void cauta(char* cheie) {
    int index = hash(cheie);
    struct Nod* curent = tabela[index];
    
    while (curent != NULL) {
        if (strcmp(curent->cheie, cheie) == 0) {
            printf("[%s]: %s\n", cheie, curent->valoare);
            return;
        }
        curent = curent->urmator;
    }
    
    printf("'%s' nu exista in dictionar.\n", cheie);
}

void sterge(char* cheie) {
    int index = hash(cheie);
    struct Nod* curent = tabela[index];
    struct Nod* anterior = NULL;
    
    while (curent != NULL) {
        if (strcmp(curent->cheie, cheie) == 0) {
            
            if (anterior == NULL)
                tabela[index] = curent->urmator;

            else
                anterior->urmator = curent->urmator;
                
            free(curent);
            printf("Sters: %s\n", cheie);
            return;
        }
        
        anterior = curent;
        curent = curent->urmator;
    }
    
    printf("'%s' nu a fost gasit.\n", cheie);
}

int main() {
    
    init();
    
    adauga("astazi", "ziua curenta");
    adauga("rezolvam", "gasi o solutie");
    adauga("laboratorul", "ora de practica");
    
    printf("\nCAUTARE\n");
    cauta("astazi");
    cauta("rezolvam");
    cauta("laboratorul");
    
    printf("\nSTERGERE\n");
    sterge("rezolvam");
    cauta("rezolvam");
    
    return 0;
}