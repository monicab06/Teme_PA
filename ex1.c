#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int key;
    struct node *next;
};

struct node *head = NULL;

// frunctie afisare
void printList() {

    struct node *ptr = head;
    printf("\n[ ");
    while(ptr != NULL) {
        printf("(%d,%d) ", ptr->key, ptr->data);
        ptr = ptr->next;
    }
    printf(" ]\n");
}

// functie numarare lungime
    int length() {
        int length = 0;
        struct node *current = head;
        for(current = head; current != NULL; current = current->next) {
            length++;
        }
        return length;
    }

// ex 1 inserare elemente
void insertFirst(int key, int data) {
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->key = key;
    link->data = data;
    link->next = head;
    head = link;
}

void insertLast(int key, int data) {
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->key = key;
    link->data = data;
    link->next = NULL;

    if(head == NULL) {
        head = link;
        return;
    }
    struct node *ptr = head;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = link;
}

void insertAfter(int afterKey, int newKey, int newData) {
    struct node *ptr = head;
    while(ptr != NULL && ptr->key != afterKey) {
        ptr = ptr->next;
    }
    if(ptr != NULL) {
        struct node *link = (struct node*) malloc(sizeof(struct node));
        link->key = newKey;
        link->data = newData;
        link->next = ptr->next;
        ptr->next = link;
    }
}

// ex 2 stergere elemente
struct node* deleteNode(int key) {
    struct node* current = head;
    struct node* previous = NULL;

    if(head == NULL) return NULL;

    while(current->key != key) {
        if(current->next == NULL) {
            return NULL;
        } else {
            previous = current;
            current = current->next;
        }
    }

    if(current == head) {
        head = head->next;
    } else {
        previous->next = current->next;
    }
    return current;
}

// ex 3 cautare element
struct node* find(int key) {
    struct node* current = head;

    if(head == NULL) {
        return NULL;
    }

    while(current->key != key) {
        if(current->next == NULL) {
            return NULL;
        } else {
            current = current->next;
        }
    }
    return current;
}

// ex 4 sortare lista
void sort() {
    int i, j, k, tempKey, tempData;
    struct node *current;
    struct node *next;

    int size = length();
    k = size;

    for ( i = 0 ; i < size - 1 ; i++, k-- ) {
        current = head;
        next = head->next;

        for ( j = 1 ; j < k ; j++ ) {
            if ( current->data > next->data ) {

                tempData = current->data;
                current->data = next->data;
                next->data = tempData;
                next->data = tempData;
                tempKey = current->key;
                current->key = next->key;
                next->key = tempKey;
            }
            current = current->next;
            next = next->next;
        }
    }
}

// ex 5 reverse lista
void reverse(struct node** head_ref) {
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;

    while (current != NULL) {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

int main() {
    printf("ex1 creare lista\n");
    insertFirst(3, 30);
    insertFirst(2, 20);
    insertFirst(1, 10);

    insertLast(4, 40);
    insertLast(5, 50);
    insertLast(7, 70);
    insertLast(8, 80);
    insertLast(9, 90);
    insertLast(10, 100);

    insertAfter(5, 6, 60);

    printList();

    printf("\n ex2 stergere element \n");
    struct node* sters = deleteNode(8);
    if(sters != NULL) free(sters);
    printList();

    printf("\n ex3 cautare element \n");
    struct node* gasit = find(7);
    if(gasit != NULL)
        printf(" gasit ", gasit->data);

    printf("\n ex4 sortare lista \n");
    sort();
    printList();

    printf("\n ex5 reverse lista \n");
    reverse(&head);
    printList();

    return 0;
}