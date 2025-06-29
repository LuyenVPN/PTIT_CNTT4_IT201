#include <stdio.h>
#include <stdlib.h>

void toBinary(int n) {
    if (n>1) {
        toBinary(n/2);
    }
    printf("%d", n%2);
}

int main() {
    int n;
    printf("nhap so nguyen bat ky: ");
    scanf("%d", &n);
    while (n<=0) {
        printf("nhap lai so nguyen duong lon hon 0: ");
        scanf("%d", &n);
    }
    printf("dang nhi phan la: ");
    toBinary(n);
    return 0;
}
