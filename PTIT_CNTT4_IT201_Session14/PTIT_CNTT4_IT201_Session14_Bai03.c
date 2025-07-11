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
void printStack(Stack*n) {
    Node *current= n->top;
    while (current!= NULL) {
        printf("%d ",current->data);
        current=current->next;
    }
}
int main() {
    Stack n;
    numberStack(&n);
    int val;
    printf("value:");
    scanf("%d", &val);
    push(&n, val);
    printStack(&n);
    return 0;
}