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
Node *deleteEnd(Node *head) {
    if (head== NULL || head->next== NULL) {
        free(head);
        return NULL;
    }
    Node *current= head;
    while (current->next!= NULL) {
        printf(" %d ",current->data);
        current=current->next;
    }
    current->prev->next=NULL;
    free(current);
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
    printf("\n Sau khi xoa:\n");
    deleteEnd(head);
    printNode(head);
    return 0;
}