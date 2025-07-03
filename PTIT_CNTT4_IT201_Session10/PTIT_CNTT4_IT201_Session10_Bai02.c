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
void printfNode(Node *head){
    Node* current = head;
    while (current !=NULL) {
        printf("data: %d\n ", current->data);
        current= current->next;
    }
};
int main() {
    Node* head= createNode(10);
    Node* node2= createNode(20);
    Node* node3= createNode(30);
    Node* node4= createNode(50);
    Node* node5= createNode(60);
    head->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    printfNode(head);
    return 0;
}