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

typedef struct Queue {
    Node **arr;
    int capacity;
    int front;
    int rear;
}Queue;
int isEmpty(Queue *queue) {
    return queue->front > queue->rear;
}

Queue *createQueue(int capacity) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->arr = (Node **)malloc(capacity * sizeof(Node *));
    q->front = 0;
    q->rear = -1;
    q->capacity = capacity;
    return q;
}
// them vao hang doi
void enQueue(Queue *queue, Node *node) {
    if (queue->rear>queue->capacity-1) {
        return;
    }
    queue->rear++;
    queue->arr[queue->rear]=node;
}
void addNode(Node *root,int value) {
    if (root==NULL) {
        return;
    }
    Queue *queue=createQueue(100);
    enQueue(queue,root);
    while (!isEmpty(queue)) {
        Node *node=queue->arr[queue->front++];
        if (node->left!=NULL) {
            enQueue(queue, node->left);
        }else {
            node->left=createNode(value);
        }
        if (node->right != NULL) {
            enQueue(queue, node->right);
        }else {
            node->right=createNode(value);
        }
    }
    free(queue->arr);
};
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
    int x;
    printf("Nhap so can them:");
    scanf("%d", &x);
    addNode(root,x);

    return 0;
}