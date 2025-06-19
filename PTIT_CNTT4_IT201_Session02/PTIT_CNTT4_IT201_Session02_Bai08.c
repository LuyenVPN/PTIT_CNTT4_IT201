#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;
    printf("nhap so phan tu muon nhap: ");
    scanf("%d",&n);
    while (n<=0 || n>100) {
        printf("nhap lai so phan tu muon nhap tu 0 den 100: ");
        scanf("%d",&n);
    }
    arr = (int *)malloc(n * sizeof(int));
    // arr = (int *)calloc(n, sizeof(int));
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("phan tu lon hon phan tu dung truoc no:");
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i-1]) {
            printf("%d ", arr[i]);
        }
    }
    free(arr);
    return 0;
}