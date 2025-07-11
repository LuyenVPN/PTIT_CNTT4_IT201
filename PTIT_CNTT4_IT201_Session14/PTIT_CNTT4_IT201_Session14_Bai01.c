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
int main() {
    Stack n;
    numberStack(&n);
    return 0;
}