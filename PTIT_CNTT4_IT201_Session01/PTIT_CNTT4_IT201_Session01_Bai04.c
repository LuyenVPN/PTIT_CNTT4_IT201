#include <stdio.h>

int main() {
    int n=10;
    int sum=0;
    for (int i=1;i<=n;i++) {
        sum+=i;
    }
    printf("tong cach 1: %d ", sum);
    //cach 1 do phuc tap la 0(n)

    int sum2= n*(n+1)/2;
    printf("tong cach 2: %d", sum2);
    //cach 2 do phuc tap la O(1)
    return 0;
}