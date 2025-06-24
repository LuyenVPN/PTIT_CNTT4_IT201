#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("nhap so luong phan tu: ");
    scanf("%d", &n);
    if (n<0) {
        printf("so luong phan tu khong duoc am");
        return 0;
    }
    if (n==0) {
        printf("so luong phan tu phai lon hon 0");
        return 0;
    }
    int *arr= (int *)malloc(n * sizeof(int));
    for (int i=0; i<n; i++) {
        printf("a[%d] =", i);
        scanf("%d", &arr[i]);
    }
    int index = 0,sum=0;
    for (int i =0; i<n; i++) {
        if (arr[i] % 2 ==0) {
            sum+=arr[i];
            index++;
        }
    }
    if (index == 0) {
        printf("khong co so nao la so chan");
        free(arr);
        return 0;
    }else {
        int average= sum /index;
        printf("trung binh cong cua so chan la: %d", average );
        free(arr);
        return 0;
    }
}