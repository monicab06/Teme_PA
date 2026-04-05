#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct{
    int arr[MAX];
    int top;
}Stack;

void initStack(Stack *s){
    s->top = -1;
}

int isFull(Stack *s){
    return s->top == MAX - 1;
}

int isEmpty(Stack *s){
    return s->top == -1;
}

void push(Stack *s, int val){
    if(!isFull(s)){
        s->arr[++(s->top)] = val;
    }
}

int pop(Stack *s){
    if(!isEmpty(s)){
        return s->arr[(s->top)--];
    }
    return 1;
}

typedef struct {
    Stack s1;
    Stack s2;
}Queue;

void initQueue(Queue *q){
    initStack(&q->s1);
    initStack(&q->s2);
}

void enqueue(Queue *q, int val){
    push(&q->s1, val);
    printf("S-a adaugat %d in coada\n", val);
}

int dequeue(Queue *q){
    if(isEmpty(&q->s1) && isEmpty(&q->s2)){
        printf("Coada este goala\n");
        return -1;
    }
    if(isEmpty(&q->s2)){
        while(!isEmpty(&q->s1)){
            push(&q->s2, pop(&q->s1));
        }
    }
    return pop(&q->s2);
}

int main(){

    Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    printf("Extragere %d din coada\n", dequeue(&q));
    enqueue(&q, 4);
    printf("Extragere %d din coada\n", dequeue(&q));
    printf("Extragere %d din coada\n", dequeue(&q));
    printf("Extragere %d din coada\n", dequeue(&q));

    return 0;
}