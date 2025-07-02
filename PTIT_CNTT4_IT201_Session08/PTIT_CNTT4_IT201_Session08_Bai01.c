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
        printf("arr[%d]= ", i);
        scanf("%d",&arr[i]);
    }
    int search;
    int found=-1;
    printf("nhap so can tim kiem: ");
    scanf("%d", &search);
    for (int i=0 ; i<n; i++) {
        if (arr[i]== search) {
            found=i;
        }
    }
    if (found==-1) {
        printf("khong ton tai");
        return 0;
    }
    printf("vi tri thu %d", found);
    return 0;
}