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
void printList(Node* head) {
    Node* current= head;
    int i=1;
    while (current != NULL) {
        printf("Node %d: %d \n",i,current->data);
        current= current->next;
        i++;
    }
    // printf("NULL\n");
}
int main() {
    Node* head=NULL;
    head= getAdd(head,10);
    head= getAdd(head,15);
    head= getAdd(head,20);
    head= getAdd(head,25);
    head= getAdd(head,30);
    printf("Danh sach lien ket: \n");
    printList(head);
    return 0;
}