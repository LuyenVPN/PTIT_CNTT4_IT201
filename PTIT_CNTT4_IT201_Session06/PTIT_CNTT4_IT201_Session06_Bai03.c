#include <stdio.h>
#include <stdlib.h>

int sum=0;
void sumN(int n) {
   if (n==0) return;
    sumN(n/10);
    sum +=n%10;
}

int main() {
    int n;
    printf("nhap so nguyen bat ky: ");
    scanf("%d", &n);
    while (n<=0) {
        printf("nhap lai so nguyen duong lon hon 0: ");
        scanf("%d", &n);
    }
    sumN(n);
    printf("Tong la: %d",sum);
    return 0;
}
