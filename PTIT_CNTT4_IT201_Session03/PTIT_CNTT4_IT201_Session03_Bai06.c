#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,m;
    int *arr;
    printf("nhap so phan tu muon nhap: ");
    scanf("%d", &n);
    if (n == 0 ) {
        printf("so luong phan tu phai lon hon 0");
        free(arr);
        return 0;
    }
    if (n < 0 ) {
        printf("so luong phan tu khong duoc am");
        free(arr);
        return 0;
    }
    arr= (int *)malloc(n*sizeof(int));
    for (int i=0; i<n; i++) {
        printf("a[%d]= ",i);
        scanf("%d", &arr[i]);
    }
    printf("nhap so phan tu muon them: ");
    scanf("%d", &m);
    while (m < 0 ) {
        printf("nhap lai so luong phan tu: ");
        scanf("%d", &m);
    }
    arr= (int *)realloc(arr, (n+m)*sizeof(int));
    for (int i=n; i<n+m; i++) {
        printf("a[%d]= ",i);
        scanf("%d", &arr[i]);
    }
    printf("mang sau khi them la: ");
    for (int i =0; i< n+m; i++) {
        printf(" %d ", arr[i]);
    }
    free(arr);
    return 0;
}