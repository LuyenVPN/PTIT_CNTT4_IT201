#include <stdio.h>
#include <stdlib.h>

int sum=0;
void sumArr (int arr[], int n) {
    if (n==0)return;
    sumArr(arr, n-1);
    sum+= arr[n-1];
}
int main() {
    int n;
    printf("nhap so phan tu muon them: ");
    scanf("%d", &n);
    while (n<=0) {
        printf("nhap lai so phan tu muon them: ");
        scanf("%d", &n);
    }
    int *arr= (int *)malloc(n*sizeof(int));
    for (int i=0; i<n; i++) {
        printf("arr[%d]= ",i);
        scanf("%d",&arr[i]);
    }
    sumArr(arr,n);
    printf("tong cac phan tu la %d", sum);
    return 0;
}