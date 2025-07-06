#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node *createNode(int data) {
    Node *newNode= (Node *)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
void printNode(Node* head) {
    Node* current= head;
    int i=1;
    while (current != NULL) {
        printf("Node %d: %d \n", i, current->data);
        i++;
        current= current->next;
    }
}
int main() {
    Node* head= createNode(10);
    Node* Node2= createNode(20);
    Node* Node3=createNode(30);
    Node* Node4=createNode(40);
    Node* Node5=createNode(50);
    head->next=Node2;
    Node2->prev=head;
    Node2->next=Node3;
    Node3->prev=Node2;
    Node3->next=Node4;
    Node4->prev=Node3;
    Node4->next=Node5;
    Node5->prev=Node4;
    printNode(head);
    return 0;
}