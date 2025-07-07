#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
Node *createNode(int data) {
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next= NULL;
    newNode->prev=NULL;
    return newNode;
}
void printNode(Node *head) {
    Node *current= head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current=current->next;
    }
    printf("NUll");
}
Node *getlength(Node *head) {
    Node* current= head;
    int i=0;
    while (current != NULL) {
        i++;
        current=current->next;
    }
    return i;
}
Node *findNumber( Node* head, int count) {
    int mid= count/2;
    Node *current= head;
    for (int i=0; i< mid; i++) {
        current= current->next;
    }
    return current;
}
int main() {
    Node *head= createNode(10);
    Node *node2= createNode(20);
    Node *node3= createNode(30);
    Node *node4= createNode(40);
    Node *node5= createNode(50);
    head->next=node2;
    node2->prev=head;
    node2->next=node3;
    node3->prev=node2;
    node3->next=node4;
    node4->prev=node3;
    node4->next=node5;
    node5->prev=node4;
    int count = getlength(head);
    int mid=0;
    Node *number= findNumber(head,count);
    if (count % 2 == 0) {
        mid= (count/2)+1;
    }else {
        mid= (count+1)/2;
    }
    printf("\n");
    printf("Nut %d: %d",mid,number->data);
    return 0;
}