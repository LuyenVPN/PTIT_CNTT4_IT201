#include <stdio.h>
#include <string.h>

int doiXung (char str[], int length, int count) {
    if ((length/2) <= 0) {
        return 1;
    }
    if (str[length - 1] == str[count]) {
        if (doiXung(str, length - 1, count + 1)) {
            return 1;
        }
    }else {
        return 0;
    }

}

int main() {
    char str[30];
    int count = 0;
    printf("nhap chuoi:");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    int length = strlen(str);
    if (doiXung(str, length, count)) {
        printf("Palindrome valid");
    }else {
        printf("Palindrome invalid");
    }

    return 0;
}
