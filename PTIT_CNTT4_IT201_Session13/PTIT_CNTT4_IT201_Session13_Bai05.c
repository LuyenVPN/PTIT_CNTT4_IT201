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
void reverseArr(int *arr, int n) {
    Stack *stack= createStack(n);
    for (int i=0; i<n;i++) {
        push(stack,arr[i]);
    }
    for (int i=0; i<n;i++) {
        arr[i] = pop(stack);
    }
}
int main() {
    int n;
    printf("n=");
    scanf("%d",&n);
    int *arr= (int *)malloc(sizeof(int) *n);
    int value;
    for (int i=0; i<n;i++) {
        printf("nhap so thu %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    reverseArr(arr,n);
    printf("\nMang sau khi sao nguoc:");
    for (int i=0; i<n;i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}