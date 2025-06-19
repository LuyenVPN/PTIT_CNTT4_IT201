#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;
    printf("nhap so phan tu muon nhap: ");
    scanf("%d", &n);
    while (n <= 0 || n > 100) {
        printf("nhap lai so phan tu muon nhap tu 0 den 100: ");
        scanf("%d", &n);
    }
    arr = (int *) malloc(n * sizeof(int));
    // arr = (int *)calloc(n, sizeof(int));
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("Mang truoc khi xoa:");
    for (int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }
    int index;
    printf("\n Nhap vi tri can xoa: ");
    scanf("%d", &index);
    if (index >= n || index < 0) {
        printf("vi tri khong co trong mang");
        return 0;
    }
    for (int i= index; i<n-1; i++) {
        arr[i]=arr[i+1];
    }
    n--;
    printf("Mang sau khi xoa la:");
    for (int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }
    free(arr);
    return 0;
}
