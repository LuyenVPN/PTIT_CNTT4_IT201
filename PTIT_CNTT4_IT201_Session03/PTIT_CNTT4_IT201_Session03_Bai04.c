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
    int max= arr[0][0];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j]>max) {
                max= arr[i][j];
            }
        }
    }
    int min= arr[0][0];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j]<min) {
                min= arr[i][j];
            }
        }
    }
    printf("phan tu lon nhat la %d \n", max);
    printf("phan tu nho nhat la %d", min);
    return 0;
}