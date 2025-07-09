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
int isFull(Stack *stack) {
    if (stack->top==stack->cap-1) {
        return 1;
    }
    return 0;
}
int push(Stack *stack ,int val) {
    if (isFull(stack)) {
        printf("Day");
        return 0;
    }
    stack->arr[++stack->top]=val;
    return 1;
}
int isEmpty(Stack *stack) {
    if (stack->top==-1) {
        return 1;
    }
    return 0;
}
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("No element in stack");
        return 0;
    }
    stack->top=stack->top-1;
    return stack->arr[stack->top+1];
}
int main() {
    Stack *myStack= createStack(5);
    int value;
    for (int i=0; i<5;i++) {
        printf("nhap so thu %d: ",i+1);
        scanf("%d",&value);
        push(myStack,value);
    }
    printf("\nLay cac phan tu ra khoi ngan xep:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\n", pop(myStack));
    }
    return 0;
}