#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52

typedef struct{
    int arr[DECK_SIZE];
    int start;
    int end;
    int size;
}Queue;

void initQueue(Queue *q){
    q->start = 0;
    q->end = -1;
    q->size = 0;
}

void enqueue(Queue *q, int val){
    if(q->size < DECK_SIZE){
        q->end = (q->end + 1) % DECK_SIZE;
        q->arr[q->end] = val;
        q->size++;
    }
}

int dequeue(Queue *q){
    if(q->size > 0){
        int val = q->arr[q->start];
        q->start = (q->start + 1) % DECK_SIZE;
        q->size--;
        return val;
    }
    return -1;
}

void printQueue(Queue *q){
    for(int i = 0; i < q->size; i++){
        int index = (q->start + i) % DECK_SIZE;
        printf("%d ", q->arr[index]);
    }
}

void shuffle(int *deck, int size){
    for(int i = size - 1; i > 0; i--){
        int j = rand() % (i + 1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int main(){

    srand(time(NULL));
    int deck[DECK_SIZE];
    for(int i = 0; i < DECK_SIZE; i++){
        deck[i] = (i % 10) + 2;
    }
    
    shuffle(deck, DECK_SIZE);

    Queue player1, player2;
    initQueue(&player1);
    initQueue(&player2);

    for(int i = 0; i < DECK_SIZE; i++){
        if(i % 2 == 0)
            enqueue(&player1, deck[i]);
        else
            enqueue(&player2, deck[i]);
    }

    int rounds = 0;
    while(player1.size > 0 && player2.size > 0){
        int card1 = dequeue(&player1);
        int card2 = dequeue(&player2);

        printf("Runda %d:\n", rounds + 1);
        printf("Jucator 1 joaca: %d\n", card1);
        printf("Jucator 2 joaca: %d\n", card2);

        if(card1 > card2){
            enqueue(&player1, card1);
            enqueue(&player1, card2);
            printf("Jucator 1 castiga runda\n");
        } else if(card2 > card1){
            enqueue(&player2, card2);
            enqueue(&player2, card1);
            printf("Jucator 2 castiga runda\n");
        } else {
            printf("Runda este egala\n");
        }

        printf("Stack Jucator 1: ");
        printQueue(&player1);
        printf("\n");

        printf("Stack Jucator 2: ");
        printQueue(&player2);
        printf("\n\n");

        rounds++;
    }

    if(player1.size > 0){
        printf("Castigator: Jucatorul 1\n");
    } else {
        printf("Castigator: Jucatorul 2\n");
    }
    printf("Numar de runde: %d\n", rounds);

    return 0;
}