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
    int found= -1;
    for (int i=0; i<n/2; i++) {
        if (arr[i]== arr[n-i-1]) {
            found=i;
            printf("cap doi xung: (%d,%d) \n", arr[i],arr[i]);
        }
    }
    if (found == -1) {
        printf(("khong co phan tu doi xung"));
        free(arr);
        return 0;
    }
    free(arr);
    return 0;
}