#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (arr[j]> arr[j+1]) {
                int temp= arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
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
    bubbleSort(arr,n);
    printf("mang sau khi sap xep: ");
    for (int i=0; i<n; i++) {
        printf("%d  ", arr[i]);
    }
    return 0;
}