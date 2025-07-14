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
int main() {
    Queue *myQueue= createQueue(5);
    for (int i=0; i<5;i++) {
        int value;
        printf("Nhap so thu %d: ",i+1);
        scanf("%d",&value);
        enQueue(myQueue,value);
    }
    printQueue(myQueue);
    return 0;
}