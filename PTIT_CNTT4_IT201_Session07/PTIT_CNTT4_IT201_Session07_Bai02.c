#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[],int n) {
    for (int i=0; i < n-1; i++) {
        int min=i;
        for (int j=i+1 ; j < n; j++) {
            if (arr[j] < arr[min]) {
               min=j;
            }
        }
        int temp= arr[i];
        arr[i]= arr[min];
        arr[min]=temp;
    }
}
int main() {
    int n;
    printf("nhap so phan tu muon them: ");
    scanf("%d", &n);
    while (n<=0 || n >= 1000) {
        printf("nhap lai so phan tu muon them: ");
        scanf("%d", &n);
    }
    int *arr= (int *)malloc(n* sizeof(int));
    for (int i=0; i<n; i++) {
        printf("a[%d]= ",i);
        scanf("%d", &arr[i]);
    }
    printf("truoc khi sap xep: ");
    for (int i=0; i<n; i++) {
        printf("a[%d]=%d  ",i, arr[i]);
    }
    selectionSort(arr,n);
    printf("\n");
    printf("Sau khi sap xep: ");
    for (int i=0; i<n; i++) {
        printf("a[%d]=%d  ",i, arr[i]);
    }
    return 0;
}