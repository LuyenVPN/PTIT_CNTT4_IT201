#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("nhap so luong phan tu: ");
    scanf("%d", &n);
    if (n<0) {
        printf("so luong phan tu khong duoc am");
        return 0;
    }
    if (n==0) {
        printf("so luong phan tu phai lon hon 0");
        return 0;
    }
    int *arr= (int *)malloc(n * sizeof(int));
    for (int i=0; i<n; i++) {
        printf("a[%d] =", i);
        scanf("%d", &arr[i]);
    }
    int min= arr[0];
    int found= 0;
    for (int i =0; i<n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            found= i;
        }
    }
    printf("phan tu nho nhat o chi so: %d", found);
    free(arr);
    return 0;
}