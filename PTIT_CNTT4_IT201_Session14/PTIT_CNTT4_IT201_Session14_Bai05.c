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
int isEmpty(Stack *stack) {
    if (stack->top== NULL) {
        printf("Rong");
        return 1;
    }
    return 0;
}
int pop(Stack *n) {
    if (isEmpty(n)) {
        return 0;
    }
    Node *curren= n->top;
    int value= curren->data;
    n->top=curren->next;
    free(curren);
    return value;
}
int printStack(Stack*n) {
    Node *current= n->top;
    while (current!= NULL) {
        printf("%d ",current->data);
        current=current->next;
    }
}
int peekBottom(Stack *n) {
    if (isEmpty(n)) {
        return 0;
    }
    Node *current= n->top;
    while (current->next != NULL) {
        current=current->next;
    }
    return current->data;
}
int main() {
    Stack n;
    numberStack(&n);
    pop(&n);
    push(&n,3);
    push(&n,1);
    int val;
    printf("\nvalue:");
    scanf("%d", &val);
    push(&n, val);
    push(&n,4);
    push(&n,9);
    printStack(&n);
    printf("\nphan tu duoi day %d", peekBottom(&n));
    return 0;
}