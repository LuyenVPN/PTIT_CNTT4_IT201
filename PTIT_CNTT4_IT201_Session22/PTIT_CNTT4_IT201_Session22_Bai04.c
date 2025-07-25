#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int n;
    int count=0;
    int matrix[100][100];
    do {
        printf("Nhap so dinh (0 < n < 100): ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 100);
    printf("Nhap ma tran ke:\n");
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            do {
                printf("A[%d][%d] = ", i, j);
                scanf("%d", &matrix[i][j]);
                if (matrix[i][j] != 0 && matrix[i][j] != 1)
                    printf("Chi duoc nhap 0 hoac 1. Nhap lai.\n");
            } while (matrix[i][j] != 0 && matrix[i][j] != 1);
            matrix[j][i] = matrix[i][j];
            if (matrix[i][j]==1) {
                count++;
            }
        }
        matrix[i][i] = 0;
    }
    printf("%d",count);
    return 0;
}