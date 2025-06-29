#include <stdio.h>
#include <stdlib.h>

void printTon(int n) {
    if (n==0) return;
    printTon(n-1);
    printf("%d \n",n);
}
int main() {
    int n;
    printf("nhap vao so nguyen duong bat ky: ");
    scanf("%d", &n);
    while (n<=0) {
        printf("nhap lai so nguyen duong tu 1 den n: ");
        scanf("%d", &n);
    }
    printf("cac so tu 1 den %d la: \n ",n);
    printTon(n);
    return 0;
}