#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;
    printf("nhap so phan tu muon nhap: ");
    scanf("%d",&n);
    while (n<=0 || n>100) {
        printf("nhap lai so phan tu muon nhap tu 0 den 100: ");
        scanf("%d",&n);
    }
    arr = (int *)malloc(n * sizeof(int));
    // arr = (int *)calloc(n, sizeof(int));
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    int index=0;
    int sum, numberSum;
    printf("nhap tong can tim:");
    scanf("%d",&sum);
    for (int i = 0; i < n; i++) {
        for (int j=i+1;j <= n;j++ ) {
            numberSum= arr[i]+ arr[j];
            if (numberSum== sum  ) {
                printf("2 so co tong can tim la: %d, %d \n", arr[i], arr[j]);
                index++;
            }
        }
    }
    if (index== 0) {
        printf("khong tim thay");
        return 0;
    }
    free(arr);
    return 0;
}