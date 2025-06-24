#include <stdio.h>
#include <stdlib.h>

int main() {
    int row, col;
    printf("nhap so hang phan tu: ");
    scanf("%d", &row);
    printf("nhap so cot phan tu: ");
    scanf("%d", &col);
    if (row <= 0 || col <= 0) {
        if (row <= 0 && col <= 0)
            printf("So hang va so cot khong hop le\n");
        else if (row <= 0)
            printf("So hang khong hop le\n");
        else
            printf("So cot khong hop le\n");
        return 0;
    }
    int **arr= (int **)malloc(row * sizeof(int*));
    for (int i=0 ; i<row; i++) {
        arr[i]= (int *)malloc(col *sizeof(int));
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    int max=0,k;
    printf("nhap so hang can tinh: ");
    scanf("%d", &k);
    if (k>row || k <= 0) {
        printf(("Hang can tinh khong ton tai"));
        return 0;
    }
    for (int j = 0; j < col; j++) {
        max += arr[k-1][j];
    }
    printf("tong phan tu la %d \n", max);
    return 0;
}