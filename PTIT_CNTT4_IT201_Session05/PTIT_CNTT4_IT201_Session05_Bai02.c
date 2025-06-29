#include <stdio.h>
#include <stdlib.h>

int sum=0;
void sumTon(int n) {
    if (n==0) return;
    sumTon(n-1);
    sum +=n;
}
int main() {
    int n;
    printf("nhap so nguyen bat ky: ");
    scanf("%d", &n);
    while (n<=0)
        printf("nhap lai so nguyem duong tu 1 den n: ");
        scanf("%d", &n);
    }
    sumTon(n);
    printf("tong tu 1 den %d la: %d",n,sum);
    return 0;
}