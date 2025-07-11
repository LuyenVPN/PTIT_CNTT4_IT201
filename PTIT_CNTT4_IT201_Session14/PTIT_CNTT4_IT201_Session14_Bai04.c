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
void printStack(Stack*n) {
    Node *current= n->top;
    while (current!= NULL) {
        printf("%d ",current->data);
        current=current->next;
    }
}
int peek(Stack *n) {
    if (isEmpty(n)) {
        return 0;
    }
    return n->top->data;
}
int main() {
    Stack n;
    numberStack(&n);
    pop(&n);
    int val;
    printf("\nvalue:");
    scanf("%d", &val);
    push(&n, val);
    push(&n,4);
    push(&n,9);
    printf("lay 1 phan tu %d \n",peek(&n) );
    // printStack(&n);
    return 0;
}