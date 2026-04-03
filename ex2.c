#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    int key;
    struct node *next;
};

struct dnode {
    int data;
    int key;
    struct dnode *prev;
    struct dnode *next;
};

struct node* insertLast(struct node *head, int key, int data) {
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->key = key;
    link->data = data;
    link->next = NULL;

    if(head == NULL) {
        return link;
    }
    struct node *ptr = head;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = link;
    return head;
}

void printList(struct node *ptr) {
    printf("[ ");
    while(ptr != NULL) {
        printf("(%d,%d) ", ptr->key, ptr->data);
        ptr = ptr->next;
    }
    printf("]\n");
}

struct dnode* insertDoubleLast(struct dnode *head, int key, int data) {
    struct dnode *link = (struct dnode*) malloc(sizeof(struct dnode));
    link->key = key;
    link->data = data;
    link->next = NULL;

    if(head == NULL) {
        link->prev = NULL;
        return link;
    }
    struct dnode *ptr = head;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = link;
    link->prev = ptr;
    return head;
}

void printDoubleList(struct dnode *ptr) {
    printf("[ ");
    while(ptr != NULL) {
        printf("(%d,%d) ", ptr->key, ptr->data);
        ptr = ptr->next;
    }
    printf("]\n");
}

// ex1 stergere duplicate
void removeDuplicates(struct node *head) {
    struct node *ptr1 = head;
    struct node *ptr2, *tempLink;

    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
        while (ptr2->next != NULL) {
            if (ptr1->data == ptr2->next->data) {
                tempLink = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(tempLink);
            } else {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}

// ex2 verificare palindrom
bool isPalindrome(struct node *head) {
    int arr[100];
    int count = 0;
    struct node *ptr = head;

    while(ptr != NULL) {
        arr[count] = ptr->data;
        ptr = ptr->next;
        count++;
    }

    int stanga = 0, dreapta = count - 1;
    while(stanga < dreapta) {
        if(arr[stanga] != arr[dreapta]) return false;
        stanga++;
        dreapta--;
    }
    return true;
}

// ex3 stergere mijloc
struct dnode* deleteMiddle(struct dnode *head) {
    if (head == NULL) return NULL;

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct dnode *slow = head;
    struct dnode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    if (slow->prev != NULL) slow->prev->next = slow->next;
    else head = slow->next;

    if (slow->next != NULL) slow->next->prev = slow->prev;

    free(slow);
    return head;
}

// ex4 inversare lista
struct node* reverseIterative(struct node *head) {
    struct node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

struct node* reverseRecursive(struct node *head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct node *rest = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return rest;
}

// ex5 combinarea 2 liste
struct node* mergeLists(struct node *head1, struct node *head2) {
    if (head1 == NULL)
        return head2;
    struct node *ptr = head1;

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = head2;

    return head1;
}

int main() {
    printf("1. Stergere duplicate\n");
    struct node *lista1 = NULL;
    lista1 = insertLast(lista1, 1, 10);
    lista1 = insertLast(lista1, 2, 20);
    lista1 = insertLast(lista1, 3, 10);
    lista1 = insertLast(lista1, 4, 30);
    lista1 = insertLast(lista1, 5, 20);

    printList(lista1);
    removeDuplicates(lista1);
    printList(lista1);

    printf("\n 2. Verificare palindrom\n");
    struct node *lista2 = NULL;
    lista2 = insertLast(lista2, 1, 55);
    lista2 = insertLast(lista2, 2, 88);
    lista2 = insertLast(lista2, 3, 55);

    printList(lista2);
    if(isPalindrome(lista2)) printf("Este palindrom\n");
    else printf("Nu este palindrom\n");

    printf("\n 3. Stergere mijloc\n");
    struct dnode *lista3 = NULL;
    lista3 = insertDoubleLast(lista3, 1, 100);
    lista3 = insertDoubleLast(lista3, 2, 200);
    lista3 = insertDoubleLast(lista3, 3, 300);
    lista3 = insertDoubleLast(lista3, 4, 400);
    lista3 = insertDoubleLast(lista3, 5, 500);

    printDoubleList(lista3);
    lista3 = deleteMiddle(lista3);
    printDoubleList(lista3);

    printf("\n 4. Inversare lista \n");
    struct node *lista4 = NULL;
    lista4 = insertLast(lista4, 1, 11);
    lista4 = insertLast(lista4, 2, 22);
    lista4 = insertLast(lista4, 3, 33);

    printList(lista4);
    lista4 = reverseIterative(lista4);
    printf("Inversata: ");
    printList(lista4);

    printf("\n 5. Combinare doua liste \n");
    struct node *listaA = NULL;
    listaA = insertLast(listaA, 1, 7);
    listaA = insertLast(listaA, 2, 8);

    struct node *listaB = NULL;
    listaB = insertLast(listaB, 3, 9);
    listaB = insertLast(listaB, 4, 10);

    printf("Lista A: "); printList(listaA);
    printf("Lista B: "); printList(listaB);

    struct node *combinata = mergeLists(listaA, listaB);
    printf("Combinate: "); printList(combinata);

    return 0;
}