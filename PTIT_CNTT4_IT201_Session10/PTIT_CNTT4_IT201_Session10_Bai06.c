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
int *find(Node* head) {
    if (head==NULL)return NULL;
    int count=0;
    Node *current= head;
    while (current != NULL) {
        current= current->next;
        count++;
    }
    return count;
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
    Node *node1=createNode(10);
    Node *node2=createNode(20);
    Node *node3=createNode(40);
    Node *node4=createNode(50);
    Node *node5=createNode(70);
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    printfNode(node1);
    int count=find(node1);
    int mid=0;
    Node *number= findNumber(node1,count);
    if (count % 2 == 0) {
       mid= (count/2)+1;
    }else {
        mid= (count+1)/2;
    }
    printf("\n");
    printf("Nut %d: %d",mid,number->data);
    return 0;
};