#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNote(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node* getAdd(Node * head, int value) {
    Node* newNode= createNote(value);
    if (head==NULL) {
        return newNode;
    }
    Node* current= head;
    while (current->next != NULL) {
        current= current->next;
    }
    current->next= newNode;
    return head;
}
int main() {
    Node* head=NULL;
    head= getAdd(head,10);
    head= getAdd(head,15);
    head= getAdd(head,20);
    head= getAdd(head,25);
    head= getAdd(head,30);
    return 0;
}