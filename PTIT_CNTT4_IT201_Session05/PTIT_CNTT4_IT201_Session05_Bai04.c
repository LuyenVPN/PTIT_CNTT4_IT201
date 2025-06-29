#include <stdio.h>
#include <stdlib.h>

int sum=0;
void numberSum(int a, int b) {
    if (a>b) return;
    numberSum(a+1, b);
    sum+= a;
}
int main() {
    int a,b;
    printf("nhap so thu nhat: ");
    scanf("%d",&a);
    printf("nhap so thu hai: ");
    scanf("%d",&b);
    if (a<=0|| b<=0) {
        printf("khong hop le");
    }
    if (a == b) {
        printf("khong hop le");
    }
    if (a > b) {
        printf("khong hop le");
    }
    numberSum(a,b);
    printf("tong trong khoang la: %d", sum);
    return 0;
}