#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
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
    for (int i=0; i<n; i++) {
        printf("so thu %d = %d \n",i+1, arr[i]);
    }
    free(arr);
    return 0;
}