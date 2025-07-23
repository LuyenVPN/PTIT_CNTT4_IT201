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

int countLeaves(Node *root) {
    if (root== NULL) {
        return 0;
    }
    if (root->left== NULL&& root->right== NULL) {
        return 1;
    }
    return countLeaves(root->left)+ countLeaves(root->right);
}
int main() {
    Node *root=NULL;
    root=createNode(1);
    Node *node1= createNode(2);
    Node *node2= createNode(3);
    Node *node3= createNode(4);
    Node *node4= createNode(5);
    Node *node5= createNode(6);
    root->left=node1;
    root->right=node2;
    node1->left=node3;
    node1->right=node4;
    node2->right=node5;
    printf("so la la: %d", countLeaves(root));

    return 0;
}