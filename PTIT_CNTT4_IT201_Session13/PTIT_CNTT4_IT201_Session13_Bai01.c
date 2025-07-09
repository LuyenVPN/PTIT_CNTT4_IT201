#include <stdlib.h>
#include <stdio.h>

typedef struct Stack {
    int *arr;
    int top;
    int cap;
}Stack;
Stack *createStack(int cap) {
    Stack *stack= (Stack *)malloc(sizeof(Stack));
    stack->top=-1;
    stack->cap=cap;
    stack->arr=(int *)malloc(sizeof(int)*cap);
    return stack;
}
int main() {
    Stack *myStack= createStack(5);
    printf("Stack duoc khoi tao. Top = %d\n", myStack->top);
    printf("Stack duoc khoi tao. Cap = %d\n", myStack->cap);
    return 0;
}