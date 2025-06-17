#include <stdio.h>

int main() {
    printDouble(10);
    return 0;
}
void printDouble (int n) {
    int i=1;
    while (i<n) {
        printf("%d\n",i);
        i*=2;
    }
}

//do phuc tap la O(log n)