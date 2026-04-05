#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct Node {
    int arr[MAX_SIZE];
    int top1;
    int top2;
} TwoStacks;

void initTwoStacks(TwoStacks *s) {
    s->top1 = -1;
    s->top2 = MAX_SIZE;
}

int push1(TwoStacks *s, int value) {
    if (s->top1 < s->top2 - 1) {
        s->top1++;
        s->arr[s->top1] = value;
        printf("S-a adaugat : %d\n", value);
        return 1;
    } else {
        printf("Stack Overflow, stiva 1 este plina!\n");
        return 0;
    }
}

int push2(TwoStacks *s, int value) {
    if(s->top1 < s->top2 - 1){
        s ->top2--;
        s->arr[s->top2] = value;
        printf("S-a adaugat : %d\n", value);
        return 1;
    } 
    else {
        printf("Stack Overflow, stiva 2 este plina!\n");
        return 0;
    }
}

int pop1(TwoStacks *s, int *value) {
    if(s->top1 >= 0){
        *value = s->arr[s->top1];
        s->top1--;
        printf("S-a scos : %d\n", *value);
        return 1;
    } else {
        printf("Stack Underflow: stiva 1 este goala!\n");
        return 0;
    }
}
int pop2(TwoStacks *s, int *value) {

    if(s->top2 < MAX_SIZE){
        *value = s->arr[s->top2];
        s->top2++;
        printf("S-a scos : %d\n", *value);
        return 1;
    } else {
        printf("Stack underflow: Stiva 2 este goala!\n");
        return 0;
    }
}

int main(){

    TwoStacks s;
    initTwoStacks(&s);

    printf("Umplerea stivelor\n");
    int val1 = 1;
    int val2 = 10;

    while(1){
        if(!push1(&s, val1))
            break;
        val1++;

        if(!push2(&s, val2))
            break;
        val2 += 10;
    }

    printf("\nGolirea stivei 1\n");
    int extract;
    while(pop1(&s, &extract)){
        printf("Stiva 1 pop: %d\n", extract);
    }
    printf("Stiva 1 s-a golit");

    printf("\nGolirea stivei 2\n");
    while(pop2(&s, &extract)){
        printf("Stiva 2 pop: %d\n", extract);
    }
    printf("Stiva 2 s-a golit");

    
    return 0;
}
