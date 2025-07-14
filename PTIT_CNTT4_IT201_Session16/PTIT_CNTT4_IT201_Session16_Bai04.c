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
Node *createNode() {
    int n;
    printf("nhap so:");
    scanf("%d",&n);
    Node *newNode= (Node*)malloc(sizeof(Node));
    newNode->data=n;
    newNode->next=NULL;
    return newNode;
}
void enQueue(Queue *q) {
    Node *newNode=createNode();
    if (q->rear==NULL) {
        q->front=newNode;
        q->rear=newNode;
    }else {
        q->rear->next=newNode;
        q->rear=newNode;
    }
}
void printQueue(Queue *q) {
    Node *temp=q->front;
    while (temp!=NULL) {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int peekQueue(Queue *q) {
    Node*temp=q->front;
    if (temp== NULL) {
        printf("queue is empty \n");
    }else{
        printf("1");
};
}
int main() {
    Queue *myQueue= createQueue();
    peekQueue(myQueue);
    enQueue(myQueue);
    enQueue(myQueue);
    enQueue(myQueue);
    peekQueue(myQueue);
    return 0;
}