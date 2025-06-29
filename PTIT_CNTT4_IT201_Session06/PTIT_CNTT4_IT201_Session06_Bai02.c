#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n, int f1, int f2) {
    if (n==0) return;
    fibonacci(n-1, f2, f1+f2);
    printf("%d  ", f1);
}

int main() {
    int n;
    printf("nhap so bat ky: ");
    scanf("%d",&n);
    fibonacci(n,0,1);
    return 0;
}
