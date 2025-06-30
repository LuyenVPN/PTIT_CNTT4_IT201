#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[],int n) {
    for (int i=0; i < n-1; i++) {
        for (int j=0 ; j < n-i-1; j++) {
            if (arr[j]> arr[j+1]) {
                int temp= arr[j];
                arr[j]= arr[j+1];
                arr[j+1]=temp;
            }
        }
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
    printf("truoc khi sap xep: ");
    for (int i=0; i<n; i++) {
        printf("a[%d]=%d  ",i, arr[i]);
    }
    bubbleSort(arr,n);
    printf("\n");
    printf("Sau khi sap xep: ");
    for (int i=0; i<n; i++) {
        printf("a[%d]=%d  ",i, arr[i]);
    }
    return 0;
}