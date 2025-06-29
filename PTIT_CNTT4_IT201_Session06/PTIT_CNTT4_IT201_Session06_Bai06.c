#include <stdio.h>
#include <stdlib.h>

int soCach(int n) {
    if (n<0) return 0;
    if ( n==0) return 1;
    return soCach(n-1)+ soCach(n-2);
}
int main() {
   int n;
   printf("nhap so bac thang: ");
   scanf("%d", &n);
   if (n<=0) {
      printf("khong hop le");
      return 1;
   }
   int check = soCach(n);
   printf("Cau thang co %d thi co %d cach", n, check);
   return 0;
}