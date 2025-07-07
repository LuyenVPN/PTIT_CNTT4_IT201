#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
Node *createNode(int data) {
    Node *newNode= (Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
void printNode(Node *head) {
    Node *current= head;
    while (current!=NULL) {
        printf("%d <-> ", current->data);
        current=current->next;
    }
    printf("NULL");
}
Node *getAtEnd(Node *head, int data) {
    Node *newNode=createNode(data);
    if (head== NULL) {
        return newNode;
    }
    Node *current= head;
    while (current->next!= NULL) {
        current=current->next;
    }
    current->next=newNode;
    newNode->prev=current;
    return head;
};
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
    printNode(head);
    int x;
    printf("\n Nhap so can them:");
    scanf("%d",&x);
    getAtEnd(head,x);
    printNode(head);
    return 0;
}