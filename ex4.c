#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 100

typedef struct{
    int arr[MAX_PLAYERS];
    int start;
    int end;
    int size;
}Queue;

void printQueue(Queue *q){
    printf("Coada actuala: ");
    for(int i = 0; i < q->size; i++){
        int index = (q->start + i) % MAX_PLAYERS;  // indexul circular
        printf("%d ", q->arr[index]);
    }
    printf("\n");
}

void initQueue(Queue *q){
    q->start = 0;
    q->end = -1;
    q->size = 0;
}

void enqueue(Queue *q, int val){
    if(q->size < MAX_PLAYERS){
        q->end = (q->end + 1) % MAX_PLAYERS;
        q->arr[q->end] = val;
        q->size++;
    }
}

int dequeue(Queue *q){
    if(q->size > 0){
        int val = q->arr[q->start];
        q->start = (q->start + 1) % MAX_PLAYERS;
        q->size--;
        return val;
    }
    return -1;
}

int main(){
    Queue q;
    initQueue(&q);

    int num_players;
    printf("Introduceti numarul de jucatori: ");
    scanf("%d", &num_players);

    for(int i = 1; i <= num_players; i++){
        enqueue(&q, i);
    }
    printQueue(&q);
    srand(time(NULL));
    

    int playersOut[MAX_PLAYERS], outCount = 0;
    
    while(q.size > 1){
        int hot_potato = (rand() % 10) + 1;
        printf("Numarul hot_potato = %d\n", hot_potato);
        for(int i = 0; i < (hot_potato - 1) % q.size; i++){
            int current_player = dequeue(&q);
            enqueue(&q, current_player);
        }

        int elim_player = dequeue(&q);
        playersOut[outCount++] = elim_player;
        printf("Player %d a fost eliminat.\n", elim_player);

    }
    
    int winner = dequeue(&q);
    playersOut[outCount++] = winner;

    printf("Jucatorul %d este castigatorul\n", winner);
    printf("Ordinea inversa a eliminarii:\n");
    for(int i = outCount - 1; i >= 0; i--){
        printf("%d ", playersOut[i]);
    }
    
    return 0;
}