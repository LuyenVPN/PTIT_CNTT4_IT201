#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[],int n) {
    for (int i=0; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j>=0 && arr[j] > temp) {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=temp;
    }
}
int main() {
    int n;
    printf("nhap so phan tu muon them: ");
    scanf("%d", &n);
    while (n<=0 || n>=1000) {
        printf("nhap lai so phan tu muon them: ");
        scanf("%d", &n);
    }
    int *arr= (int *)malloc(n* sizeof(int));
    for (int i=0; i<n; i++) {
        printf("a[%d]= ",i);
        scanf("%d", &arr[i]);
    }
    printf("Truoc khi sap xep: ");
    for (int i=0; i<n; i++) {
        printf("a[%d]=%d  ",i, arr[i]);
    }
    insertionSort(arr,n);
    printf("\n");
    printf("Sau khi sap xep: ");
    for (int i=0; i<n; i++) {
        printf("a[%d]=%d  ",i, arr[i]);
    }
    return 0;
}