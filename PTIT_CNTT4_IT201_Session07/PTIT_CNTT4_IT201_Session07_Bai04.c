#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sapxepchuoi(char str[]) {
    char temp;
    int n=strlen(str);
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (str[i]> str[j]) {
                temp= str[i];
                str[i]=str[j];
                str[j]=temp;
            }
        }
    }
}

int main() {
    char str[100];
    printf("nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")]='\0';
    printf("chuoi truoc khi sap xep: %s \n", str);
    sapxepchuoi(str);
    printf("chuoi sau khi sap xep: %s \n", str);
    return 0;
}
