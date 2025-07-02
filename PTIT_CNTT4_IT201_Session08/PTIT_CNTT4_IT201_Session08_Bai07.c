#include <stdio.h>

void swap(int *a, int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int left, int right) {
    int pivot=arr[right];
    int i=left-1;
    for (int j=left; j<right;j++) {
        if (arr[j]<=pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1],&arr[right]);
    return i+1;
}
void quickSort(int arr[],int left, int right) {
    if (left<right) {
        int pivoIndex= partition(arr,left,right);
        quickSort(arr,left,pivoIndex-1);
        quickSort(arr,pivoIndex+1,right);
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
    quickSort(arr,0,n-1);
    printf("mang sau khi sap xep: ");
    for (int i=0; i<n; i++) {
        printf("%d  ", arr[i]);
    }
    return 0;
}