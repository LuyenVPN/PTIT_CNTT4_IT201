#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node *createNode(int data) {
    Node *newNode= (Node *)malloc(sizeof(Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}


int main() {
    Node *root=NULL;
    int data;
    printf("Nhap gia tri can them:");
    scanf("%d",&data);
    root=createNode(data);
    return 0;
}