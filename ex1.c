#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

void printPostOrder(struct node* root) {
    if (root != NULL) {
        printPostOrder(root->leftChild);
        printPostOrder(root->rightChild);
        printf("%d ", root->data);
    }
}

int max(int a, int b) {
    if (a > b)
        return a;
    else 
        return b;
}

int checkBalance(struct node *current) {
    if (current == NULL) return 0;
    
    int leftHeight = checkBalance(current->leftChild);
    if (leftHeight == -1) return -1;
    
    int rightHeight = checkBalance(current->rightChild);
    if (rightHeight == -1) return -1;
    
    int diff = abs(leftHeight - rightHeight);
    if (diff > 1) return -1;
    
    return max(leftHeight, rightHeight) + 1;
}

int isBalanced(struct node *root) {
    return checkBalance(root) != -1;
}

int main() {
    struct node* root = createNode(1);
    root->leftChild = createNode(2);
    root->rightChild = createNode(3);
    root->leftChild->leftChild = createNode(4);

    printf("Traversare Post-ordine: ");
    printPostOrder(root);
    printf("\n");

    if (isBalanced(root)) printf("Arborele ESTE echilibrat.\n");
    else printf("Arborele NU este echilibrat.\n");

    return 0;
}