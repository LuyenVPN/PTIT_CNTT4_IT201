#include <stdio.h>
#include <stdlib.h>

int max,min;
void find(int arr[], int i, int n) {
   if (i>=n) return;
    if (arr[i] > max) {
        max= arr[i];
    }
    if (arr[i] < min) {
        min = arr[i];
    }
    find(arr,i+1,n);
}

int main() {
    int n;
    printf("nhap so nguyen bat ky: ");
    scanf("%d", &n);
    while (n<=0) {
        printf("nhap lai so nguyen duong lon hon 0: ");
        scanf("%d", &n);
    }
    int arr[n];
    for (int i=0; i<n; i++) {
        printf("a[%d]= ",i);
        scanf("%d", &arr[i]);
    }
    max=min= arr[0];
    find(arr,1,n);
    printf("so lon nhat la: %d \n",max);
    printf("so nho nhat la: %d",min);
    return 0;
}
