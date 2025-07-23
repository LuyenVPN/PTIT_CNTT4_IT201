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
int search(Node *root,int target) {
    if (root==NULL) {
        return 0;
    }
    int level=0;
    Queue *queue=createQueue(100);
    enQueue(queue,root);
    while (!isEmpty(queue)) {
        int size = queue->rear - queue->front + 1;
        for (int i = 0; i < size; i++) {
            Node *node = queue->arr[queue->front++];
            if (node->data == target) {
                return level;
            }
            if (node->left != NULL)
                enQueue(queue, node->left);
            if (node->right != NULL)
                enQueue(queue, node->right);
        }
        level++;
    }
    free(queue->arr);
    free(queue);
    return -1;
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
    int x;
    printf("Nhap so can tim:");
    scanf("%d", &x);
    int level=search(root,x);
    if (level==-1) {
        printf("khong co so can tim");
    }else {
        printf("Node level: %d",search(root,x));
    }

    return 0;
}