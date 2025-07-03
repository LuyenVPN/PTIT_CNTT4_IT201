#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node *createNode(int value) {
    Node *newNode= (Node *)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
void printfNode(Node *head) {
    Node* current=head;
    while (current != NULL) {
        printf("%d->", current->data);
        current= current->next;
    }
    printf("NULL");
}
Node* deleteNumber(Node *head, int n) {
    while (head!= NULL && head->data == n) {
        Node* temp= head;
        head=head->next;
        free(temp);
    }
    if (head== NULL) return NULL;
    Node* current = head;
    while (current->next != NULL) {
        if (current->next->data== n) {
            Node* temp= current->next;
            current->next= temp->next;
            free(temp);
        }else {
            current= current->next;
        }
    }
    return head;
}
int main() {
    Node *node1=createNode(10);
    Node *node2=createNode(20);
    Node *node3=createNode(30);
    Node *node4=createNode(10);
    Node *node5=createNode(10);
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    printfNode(node1);
    int n;
    printf("\nNhap so can xoa:");
    scanf("%d",&n);
    node1= deleteNumber(node1, n);
    printfNode(node1);
    return 0;
};