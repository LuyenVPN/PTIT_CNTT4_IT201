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

void preorderDFS(Node *root) {
    if (root==NULL) {
        return;
    }
    printf("%d  ",root->data);
    preorderDFS(root->left);
    preorderDFS(root->right);
}
void inorderDFS(Node *root) {
    if (root==NULL) {
        return;
    }
    inorderDFS(root->left);
    printf("%d  ",root->data);
    inorderDFS(root->right);
}
void portorderDFS(Node *root) {
    if (root==NULL) {
        return;
    }
    portorderDFS(root->left);
    portorderDFS(root->right);
    printf("%d  ",root->data);
}
int searchDFS(Node* root, int target) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == target) {
        return 1;
    }
    return searchDFS(root->left, target) || searchDFS(root->right, target);
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
    preorderDFS(root);
    printf("\n");
    inorderDFS(root);
    printf("\n");
    portorderDFS(root);
    int x;
    printf("Nhasp so can tim:");
    scanf("%d",&x);
    if (searchDFS(root,x)) {
        printf("True");
    }else {
        printf("flase");
    }
    return 0;
}