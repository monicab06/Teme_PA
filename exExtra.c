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


void solveZigZag(struct node* root, int isLeft, int currentLen, int* maxLen) {
    if (root == NULL) {
        return;
    }

    if (currentLen > *maxLen) {
        *maxLen = currentLen;
    }

    if (isLeft) {

        solveZigZag(root->rightChild, 0, currentLen + 1, maxLen);
        
        solveZigZag(root->leftChild, 1, 1, maxLen);
    } else {

        solveZigZag(root->leftChild, 1, currentLen + 1, maxLen);
        
        solveZigZag(root->rightChild, 0, 1, maxLen);
    }
}

int longestZigZag(struct node* root) {
    if (root == NULL) {
        return 0;
    }

    int maxLen = 0; 
    solveZigZag(root->leftChild, 1, 1, &maxLen);
    solveZigZag(root->rightChild, 0, 1, &maxLen);

    return maxLen;
}

int main() {

    struct node* root = createNode(1);
    root->rightChild = createNode(2);
    root->rightChild->leftChild = createNode(3);
    root->rightChild->rightChild = createNode(4);
    root->rightChild->leftChild->rightChild = createNode(5);
    root->rightChild->leftChild->rightChild->leftChild = createNode(6);

    printf("Traversare Pre-ordine a arborelui: ");
    printPreOrder(root);
    printf("\n");

    int rezultat = longestZigZag(root);
    printf("Cea mai lunga cale ZigZag are lungimea: %d\n", rezultat);

    return 0;
}