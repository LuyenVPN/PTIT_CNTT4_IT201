#include <stdio.h>


int main() {
    int n;
    printf("nhap so luong phan tu: ");
    scanf("%d", &n);
    while (n<=0 || n>1000) {
        printf("nhap so luong phan tu: ");
        scanf("%d", &n);
    }
    int arr[n];
    for (int i=0; i<n; i++) {
        printf("arr[%d]= ",i );
        scanf("%d", &arr[i]);
    }
    int search;
    int found =-1;
    printf("nhap so can tim: ");
    scanf("%d", &search);
    int left=0;
    int right= n-1;
    while (left<= right) {
        int mid= (left+right)/2;
        if (arr[mid]== search) {
            found=mid;
            break;
        }else if (arr[mid] < search) {
            left= mid+1;
        }else {
            right= mid-1;
        }
    }
    if (found ==-1) {
        printf("khong tim thay");
        return 0;
    }
    printf("phan tu vi tri thu %d", found);
    return 0;
}