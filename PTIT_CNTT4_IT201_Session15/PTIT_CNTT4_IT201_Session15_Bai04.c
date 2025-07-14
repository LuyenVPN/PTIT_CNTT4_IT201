#include <stdlib.h>
#include <stdio.h>

typedef struct Queue{
    int *arr;
    int front;
    int rear;
    int capacity;
}Queue;
Queue *createQueue(int capacity) {
    Queue *queue= (Queue *)malloc(sizeof(Queue));
    queue->arr=(int*)malloc(sizeof(int)*capacity);
    queue->front=0;
    queue->rear=-1;
    queue->capacity=capacity;
    return queue;
}
void enQueue( Queue *queue,int value) {
    if (queue->rear==queue->capacity-1) {
        printf("Day");
        return;
    }
    queue->rear=queue->rear+1;
    queue->arr[queue->rear]=value;
}
void printQueue(Queue *queue) {
    for (int i=queue->front;i<=queue->rear;i++) {
        printf("%d ",queue->arr[i]);
    }
}
int isEmpty(Queue *queue) {
    if (queue->rear<queue->front) {
        return 1;
    }
    return 0;
}

int main() {
    Queue *myQueue= createQueue(5);
    enQueue(myQueue,1);
    enQueue(myQueue,5);
    printQueue(myQueue);
    return 0;
}