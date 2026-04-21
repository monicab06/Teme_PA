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

int getLevel(struct node* root, int val, int level) {
    if (root == NULL)
        return 0;
    if (root->data == val)
        return level;
    
    int leftLevel = getLevel(root->leftChild, val, level + 1);
    if (leftLevel != 0)
        return leftLevel;
    return getLevel(root->rightChild, val, level + 1);
}

int isSibling(struct node* root, int a, int b) {
    if (root == NULL) return 0;
    if (root->leftChild != NULL && root->rightChild != NULL) {
        if ((root->leftChild->data == a && root->rightChild->data == b) ||
            (root->leftChild->data == b && root->rightChild->data == a))
            return 1;
    }
    return isSibling(root->leftChild, a, b) || isSibling(root->rightChild, a, b);
}

int isCousin(struct node* root, int a, int b) {
    int levelA = getLevel(root, a, 1);
    int levelB = getLevel(root, b, 1);
    if ((levelA == levelB) && (levelA != 0) && !isSibling(root, a, b))
        return 1;
    return 0;
}

int main() {
    
    struct node* root = createNode(1);
    root->leftChild = createNode(2);
    root->rightChild = createNode(3);
    root->leftChild->leftChild = createNode(4);
    root->rightChild->rightChild = createNode(5);

    printf("Traversare Post-ordine: ");
    printPostOrder(root);
    printf("\n");

    if (isCousin(root, 4, 5)) 
        printf("Nodurile 4 si 5 sunt verisori.\n");
    else
        printf("Nodurile 4 si 5 NU sunt verisori.\n");

    return 0;
}