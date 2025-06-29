#include <stdio.h>
#include <stdlib.h>
int sum=1;
void factorial(int n) {
    if (n==0)return;
    factorial(n-1);
    sum *= n;
}
int main() {
    int n;
    printf("nhap mot so nguyen duong bat ky: ");
    scanf("%d", &n);
    while (n<=0) {
        printf("nhap lai so nguyen: ");
        scanf("%d", &n);
    }
    factorial(n);
    printf("tong giai thua la: %d", sum);
    return 0;
}