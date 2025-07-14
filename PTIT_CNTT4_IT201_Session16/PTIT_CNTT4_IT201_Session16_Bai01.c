#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;
typedef struct Queue {
    Node *front;
    Node *rear;
}Queue;
Queue *createQueue() {
    Queue *q= (Queue*)malloc(sizeof(Queue));
    q->front=NULL;
    q->rear=NULL;
    return q;
}