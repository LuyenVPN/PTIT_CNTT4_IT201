#include <stdio.h>

void merge(int arr[],int left, int mid, int right) {
    int leftlenght= mid-left+1;
    int rightlenght= right- mid;
    int leftArr[leftlenght], rightArr[rightlenght];
    for (int i=0; i< leftlenght; i++) {
        leftArr[i]=arr[left+i];
    }
    for (int j=0; j< rightlenght; j++) {
        rightArr[j]=arr[mid+1+j];
    }
    int leftArrIndex=0;
    int rightArrIndex=0;
    int arrIndex= left;
    while ((leftArrIndex< leftlenght)&& (rightArrIndex < rightlenght)) {
        if (leftArr[leftArrIndex]<= rightArr[rightArrIndex]) {
            arr[arrIndex]=leftArr[leftArrIndex];
            leftArrIndex++;
        }else {
            arr[arrIndex]=rightArr[rightArrIndex];
            rightArrIndex++;
        }
        arrIndex++;
    }
    while (leftArrIndex< leftlenght) {
        arr[arrIndex]= leftArr[leftArrIndex];
        leftArrIndex++;
        arrIndex++;
    }
    while (rightArrIndex< rightlenght) {
        arr[arrIndex]= rightArr[rightArrIndex];
        rightArrIndex++;
        arrIndex++;
    }
}
void mergeSort(int arr[], int left, int right) {
    if (left== right) {
        return;
    }
    int mid= (left+right)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
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
    mergeSort(arr, 0, n - 1);
    printf("mang sau khi sap xep: ");
    for (int i=0; i<n; i++) {
        printf("%d  ", arr[i]);
    }
    return 0;
}