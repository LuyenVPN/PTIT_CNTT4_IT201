#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node *next;
}Node;

Node *createNode(int value) {
    Node *newNode= (Node *)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next= NULL;
    return newNode;
}

int main() {
    Node* head=createNode(10);
    Node* node2= createNode(20);
    Node* node3= createNode(30);
    Node* node4= createNode(50);
    Node* node5= createNode(60);
    head->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    return 0;
}