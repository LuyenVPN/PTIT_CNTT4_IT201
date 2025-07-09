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
int isPalindrome(char *str) {
    int len = strlen(str);
    Stack *stack = createStack(len);
    for (int i = 0; i < len; i++) {
        push(stack, str[i]);
    }
    for (int i = 0; i < len; i++) {
        if (str[i] != pop(stack)) {
            free(stack->arr);
            free(stack);
            return 0;
        }
    }
    return 1;
}
int main() {
    char str[100];
    printf("nhap chuoi:");
    scanf("%s",&str);
    if (isPalindrome(str)) {
        printf("true");
    }else {
        printf("flase");
    }
    return 0;
}