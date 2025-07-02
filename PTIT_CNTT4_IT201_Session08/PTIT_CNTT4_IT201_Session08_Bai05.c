#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i=0; i<n; i++) {
        int temp=arr[i];
        int j= i-1;
        while(arr[j] > temp && j>=0) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
int main() {
    int n;
    printf("nhap so luong muon nhap: ");
    scanf("%d", &n);
    if (n<=0|| n>1000) {
        printf("so luong phan tu khong hop le");
        return 0;
    }
    int arr[n];
    for (int i=0; i< n; i++) {
        printf("a[%d]= ", i);
        scanf("%d", &arr[i]);
    }
    insertionSort(arr,n);
    printf("mang sau khi sap xep: ");
    for (int i=0; i<n; i++) {
        printf("%d  ", arr[i]);
    }
    return 0;
}