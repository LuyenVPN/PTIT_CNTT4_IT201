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
    printf("Mang truoc khi them:");
    for (int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }
    int index;
    int number;
    printf("\n Nhap vi tri can them: ");
    scanf("%d", &index);
    if (index >= n || index < 0) {
        printf("vi tri khong co trong mang");
        return 0;
    }
    printf("nhap gia tri muon them: ");
    scanf("%d", &number);
    arr = (int *)realloc(arr, (n+1)*sizeof(int));
    for (int i= n; i> index; i-- ) {
        arr[i]= arr[i-1];
    }
    arr[index]=number;
    n++;
    printf("Mang sau khi them la:");
    for (int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }
    free(arr);
    return 0;
}
