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

void printInOrder(struct node* root) {
    if (root != NULL) {
        printInOrder(root->leftChild);
        printf("%d ", root->data);
        printInOrder(root->rightChild);
    }
}

int isBSTUtil(struct node *current, struct node *minNode, struct node *maxNode) {
    if (current == NULL) return 1;
    if (minNode != NULL && current->data <= minNode->data)
        return 0;
    if (maxNode != NULL && current->data >= maxNode->data)
        return 0;
    return isBSTUtil(current->leftChild, minNode, current) && 
           isBSTUtil(current->rightChild, current, maxNode);
}

int isBST(struct node *root) {
    return isBSTUtil(root, NULL, NULL);
}

int main() {
    struct node* root = createNode(20);
    root->leftChild = createNode(10);
    root->rightChild = createNode(30);

    printf("Traversare In-ordine: ");
    printInOrder(root);
    printf("\n");

    if (isBST(root))
        printf("Arborele ESTE un BST valid.\n");
    else
        printf("Arborele NU este un BST valid.\n");

    return 0;
}