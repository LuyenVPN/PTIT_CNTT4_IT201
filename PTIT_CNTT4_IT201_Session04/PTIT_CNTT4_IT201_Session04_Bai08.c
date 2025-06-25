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
    for (int i=0; i<n; i++) {
        if (arr[i]== sreach) {
            found=i;
            printf("vi tri: %d \n", i);
        }
    }
    if (found == -1) {
        printf(("phan tu khong co trong mang"));
        free(arr);
        return 0;
    }
    free(arr);
    return 0;
}