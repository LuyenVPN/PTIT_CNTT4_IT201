#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct  Node *next;
}Node;
typedef struct {
    Node *top;
}Stack;
void numberStack(Stack *n){
    n->top=NULL;
};
void push(Stack *n, int data) {
    Node *newNode= (Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next= n->top;
    n->top=newNode;
}
int main() {
    Stack n;
    numberStack(&n);
    int val;
    printf("value:");
    scanf("%d", &val);
    push(&n, val);
    return 0;
}