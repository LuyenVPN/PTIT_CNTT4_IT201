#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    struct Student{
        int id;
        char name[50];
        int age;
    };
    struct Student student[5];
    for (int i =0; i<3;i++ ) {
        printf("sinh vien thu %d \n",i+1);
        printf("Id: ");
        scanf("%d",&student[i].id);
        getchar();
        printf("Name: ");
        fgets(student[i].name,50, stdin);
        student[i].name[strlen(student[i].name)-1]='\0';
        printf("Age: ");
        scanf("%d", &student[i].age);
    }
    int search;
    printf("nhap id can tim: ");
    scanf("%d",&search);
    for (int i=0; i<3; i++) {
        if (student[i].id == search) {
            printf("Id: %d, Name: %s, Age:%d ", student[i].id, student[i].name, student[i].age);
            return 0;
        }
    }
    printf("Sinh vien khong ton tai");
    return 0;
}
