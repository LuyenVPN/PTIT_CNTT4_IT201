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
    int max=arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max= arr[i];
        }
    }
    printf("phan tu lon nhat la: %d", max);
    free(arr);
    return 0;
}