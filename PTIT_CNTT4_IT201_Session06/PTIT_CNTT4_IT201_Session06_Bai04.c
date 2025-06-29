#include <stdio.h>
#include <stdlib.h>

void thaphanoi(int n, char cot1, char cot3, char cot2) {
    if (n==1) {
        printf("Di chuyen dia 1 tu cot %c sang cot %c \n",cot1, cot3);
        return;
    }
    thaphanoi(n-1,cot1,cot2,cot3);
    printf("Di chuyen dia %d tu cot %c sang cot %c \n",n, cot1, cot3);
    thaphanoi(n-1,cot2,cot3,cot1);
}

int main() {
    int n;
    printf("nhap so nguyen duong:");
    scanf("%d", &n);
    printf("Cac buoc di chuyen tu cot a sang cot c:\n");
    thaphanoi(n,'A','C','B');
    return 0;
}
