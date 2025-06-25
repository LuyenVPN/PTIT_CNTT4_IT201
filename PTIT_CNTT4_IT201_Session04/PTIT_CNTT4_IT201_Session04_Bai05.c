#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("nhap so luong phan tu muon them:");
    scanf("%d", &n);
    if (n<=0) {
        printf("so luong khong hop le");
    }
    int *arr= (int *)malloc(n* sizeof(int));
    for (int i=0; i<n;i++) {
        printf("arr[%d]= ", i);
        scanf("%d",&arr[i]);
    }
    int sreach;
    int found= -1;
    printf("nhap so can tim: ");
    scanf("%d", &sreach);
    int left=0;
    int right = n-1;
    while (left<= right) {
        int mid= (left+right)/2;
        if (arr[mid] == sreach) {
            found=mid;
            break;
        }else if (arr[mid]< sreach) {
            left = mid+1;
        }else {
            right= mid-1;
        }
    }
    if (found == -1) {
        printf(("phan tu khong co trong mang"));
        free(arr);
        return 0;
    }
    printf("phan tu co trong mang", found);
    free(arr);
    return 0;
}