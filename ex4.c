#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void serialize(struct node* root, char* buffer) {
    if (root == NULL) {
        strcat(buffer, "N ");
        return;
    }
    char temp[20];
    sprintf(temp, "%d ", root->data);
    strcat(buffer, temp);
    serialize(root->leftChild, buffer);
    serialize(root->rightChild, buffer);
}

struct node* deserializeUtil(char** ptr) {
    while (**ptr == ' ') (*ptr)++;
    if (**ptr == '\0') return NULL;
    if (**ptr == 'N') {
        (*ptr)++;
        return NULL;
    }
    
    int val = 0, sign = 1;
    if (**ptr == '-') { sign = -1; (*ptr)++; }
    while (**ptr >= '0' && **ptr <= '9') {
        val = val * 10 + (**ptr - '0');
        (*ptr)++;
    }
    val *= sign;

    struct node* root = createNode(val);
    root->leftChild = deserializeUtil(ptr);
    root->rightChild = deserializeUtil(ptr);
    return root;
}

struct node* deserialize(char* data) {
    char* ptr = data;
    return deserializeUtil(&ptr);
}

int main() {
    struct node* root = createNode(10);
    root->leftChild = createNode(5);
    root->rightChild = createNode(15);

    char buffer[1024] = ""; 
    serialize(root, buffer);
    printf("String serializat: %s\n", buffer);

    struct node* newRoot = deserialize(buffer);
    
    printf("Traversare In-ordine a arborelui reconstruit: ");
    printInOrder(newRoot);
    printf("\n");

    return 0;
}