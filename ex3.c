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

void printPreOrder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        printPreOrder(root->leftChild);
        printPreOrder(root->rightChild);
    }
}

struct node* findLCA(struct node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;

    struct node* leftLCA = findLCA(root->leftChild, n1, n2);
    struct node* rightLCA = findLCA(root->rightChild, n1, n2);

    if (leftLCA != NULL && rightLCA != NULL) 
        return root;
    if (leftLCA != NULL)
        return leftLCA; 
     else 
        return rightLCA; 
}

int main() {
    struct node* root = createNode(1);
    root->leftChild = createNode(2);
    root->rightChild = createNode(3);
    root->leftChild->leftChild = createNode(4);
    root->leftChild->rightChild = createNode(5);

    printf("Traversare Pre-ordine: ");
    printPreOrder(root);
    printf("\n");

    struct node* lca = findLCA(root, 4, 5);
    if (lca != NULL) printf("Cel mai apropiat stramos comun pentru 4 si 5 este: %d\n", lca->data);

    return 0;
}