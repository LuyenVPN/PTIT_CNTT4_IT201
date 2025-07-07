#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node* createNode(int data) {
    Node *newNode= (Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next= NULL;
    newNode->prev= NULL;
    return newNode;
}
void printNode(Node *head) {
    Node *current=head;
    while (current!=NULL) {
        printf("%d <-> ",current->data);
        current=current->next;
    }
    printf("NULL");
}
//xoa dau
Node *deleteNode(Node *head){
    if (head== NULL) {
        return NULL;
    }
    Node *current=head;
    head= head->next;
    if (head!= NULL) {
        head->prev=NULL;
    }
    free(current);
    return head;
}
// xoa cuoi
Node *deleteLastNode(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->prev->next = NULL;
    free(current);

    return head;
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
    printf("\n Sau khi xoa:\n");
    head=deleteLastNode(head);
    printNode(head);
    return 0;
}
