#include <stdio.h>

int main(){
    int a[]={1,4,3,2,3,3};
    int n= sizeof(a)/sizeof(a[0]);
    int count=0;
    int number=0;
    for (int i=0; i<n;i++) {
        int temp=0;
        for (int j=0; j<n; j++) {
            if (a[i]==a[j]) {
                temp++;
            }
        }
        if (temp>count) {
            count=temp;
            number=a[i];
        }
    }

    printf("phan tu xuat hien nhieu nhat la: %d",number);
    return 0;
}
// do phuc tap la o(n)