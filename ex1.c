#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmptyStack(Stack *s) {
    return s->top == -1;
}

int isFullStack(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, int val) {
    if (isFullStack(s)) {
        printf("Stack plin! Nu se poate adauga %d\n", val);
        return;
    }
    s->arr[++s->top] = val;
    printf("Push: %d | Stack acum: ", val);
    for(int i = 0; i <= s->top; i++)
        printf("%d ", s->arr[i]);
    printf("\n");
}

int pop(Stack *s) {
    if (isEmptyStack(s)) {
        printf("Stack gol!\n");
        return -1;
    }
    int val = s->arr[s->top--];
    printf("Pop: %d | Stack acum: ", val);
    for(int i = 0; i <= s->top; i++)
        printf("%d ", s->arr[i]);
    printf("\n");
    return val;
}

int peekStack(Stack *s) {
    if (isEmptyStack(s)) {
        printf("Stack gol!\n");
        return -1;
    }
    return s->arr[s->top];
}

typedef struct {
    int arr[MAX_SIZE];
    int start, end;
    int size;
} Queue;

void initQueue(Queue *q) {
    q->start = 0;
    q->end = -1;
    q->size = 0;
}

int isEmptyQueue(Queue *q) {
    return q->size == 0;
}

int isFullQueue(Queue *q) {
    return q->size == MAX_SIZE;
}

void enqueue(Queue *q, int val) {
    if (isFullQueue(q)) {
        printf("Queue plin! Nu se poate adauga %d\n", val);
        return;
    }
    q->end = (q->end + 1) % MAX_SIZE;
    q->arr[q->end] = val;
    q->size++;
    printf("Enqueue: %d | Queue acum: ", val);
    for(int i = 0; i < q->size; i++) {
        int idx = (q->start + i) % MAX_SIZE;
        printf("%d ", q->arr[idx]);
    }
    printf("\n");
}

int dequeue(Queue *q) {
    if (isEmptyQueue(q)) {
        printf("Queue gol!\n");
        return -1;
    }
    int val = q->arr[q->start];
    q->start = (q->start + 1) % MAX_SIZE;
    q->size--;
    printf("Dequeue: %d | Queue acum: ", val);
    for(int i = 0; i < q->size; i++) {
        int idx = (q->start + i) % MAX_SIZE;
        printf("%d ", q->arr[idx]);
    }
    printf("\n");
    return val;
}

int peekQueue(Queue *q) {
    if (isEmptyQueue(q)) {
        printf("Queue gol!\n");
        return -1;
    }
    return q->arr[q->start];
}

int main() {
    Stack s;
    Queue q;

    initStack(&s);
    initQueue(&q);

    printf("Testare: \n");

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Peek stack: %d\n", peekStack(&s));

    pop(&s);
    pop(&s);

    push(&s, 40);
    push(&s, 50);
    push(&s, 60);
    push(&s, 70); 

    if (isFullStack(&s)) printf("Stack este plin\n");

    printf("\nTestare:\n");

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    printf("Peek queue: %d\n", peekQueue(&q));

    dequeue(&q);
    dequeue(&q);

    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);
    enqueue(&q, 7); 

    if (isFullQueue(&q)) printf("Queue este plin\n");

    return 0;
}
