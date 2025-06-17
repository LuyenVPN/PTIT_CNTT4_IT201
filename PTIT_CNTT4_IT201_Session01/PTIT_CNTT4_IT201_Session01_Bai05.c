#include <stdio.h>

int main() {
    int arr[]={45,64,34,23,67,86};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i=0;i<n-1;i++) {
        int index= i;
        for (int j=i+1; j<n;j++) {
            if (arr[j]<arr[index]) {
                index=j;
            }
        }
        int temp= arr[index];
        arr[index]= arr[i];
        arr[i]=temp;
    }
    for (int i=0; i<n; i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}
//do phuc tap O(n^2)