#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        int min=i;
        for (int j=i+1; j<n; j++) {
            if (arr[j]< arr[min]) {
                min=j;
            }
        }
        if (min != i) {
            int temp= arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
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
    selectionSort(arr,n);
    printf("mang sau khi sap xep: ");
    for (int i=0; i<n; i++) {
        printf("%d  ", arr[i]);
    }
    return 0;
}