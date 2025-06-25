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
        }
    }
    if (found == -1) {
        printf(("khong co"));
        free(arr);
        return 0;
    }
    printf("chi so cua phan tu la: %d", found);
    free(arr);
    return 0;
}