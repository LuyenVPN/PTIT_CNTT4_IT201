#include <stdio.h>

int main() {
    int a[]={1,4,3,2,3,3};
    int n= sizeof(a)/sizeof(a[0]);
    int b;
    int temp=0;
    printf("nhap so can tim:");
    scanf("%d",&b);
    for (int i=0; i<n;i++) {
        if (a[i]==b) {
            temp++;
        }
    }
    if (temp==0) {
        printf("khong co so trong mang");
        return 0;
    }
    printf("so lan xuat hien la: %d",temp);
    return 0;
}
// do phuc tap la o(n)