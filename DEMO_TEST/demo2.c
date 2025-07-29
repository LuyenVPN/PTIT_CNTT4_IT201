#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int id;
    char name[100];
    int status;
    int avg;
} Student;

typedef struct Node {
    Student data;
    struct Node *next;
    struct Node *prev;
} Node;

Student* studentArray = NULL;
int count = 0;
int capacity = 0;
Node *inactiveHead = NULL;
Node *inactiveTail = NULL;
int nextId = 1;

void ensureCapacity() {
    if (count >= capacity) {
        capacity = (capacity == 0) ? 2 : capacity * 2;
        studentArray = (Student*)realloc(studentArray, capacity * sizeof(Student));
        if (!studentArray) {
            printf("Khong du bo nho!\n");
            exit(1);
        }
    }
}

void addToInactiveList(Student student) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = student;
    newNode->next = NULL;
    newNode->prev = inactiveTail;
    if (inactiveTail) {
        inactiveTail->next = newNode;
    } else {
        inactiveHead = newNode;
    }
    inactiveTail = newNode;
}

void addStudent() {
    ensureCapacity();
    Student student;
    student.id = nextId++;

    getchar();
    printf("Nhap ten: ");
    fgets(student.name, sizeof(student.name), stdin);
    student.name[strcspn(student.name, "\n")] = '\0';

    printf("Nhap diem trung binh: ");
    scanf("%d", &student.avg);

    student.status = 1;
    studentArray[count++] = student;
    printf("Da them sinh vien ID: %d\n", student.id);
}

void showStudent() {
    if (count == 0) {
        printf("Danh sach trong!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Ten: %s | Diem TB: %d | Trang thai: %s\n",
            studentArray[i].id,
            studentArray[i].name,
            studentArray[i].avg,
            studentArray[i].status ? "Hoat dong" : "Khong hoat dong");
    }
}

void deleteStudent() {
    int id;
    printf("Nhap ID muon xoa: ");
    scanf("%d", &id);
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (studentArray[i].id == id) {
            found = 1;
            if (studentArray[i].status == 0) {
                addToInactiveList(studentArray[i]);
            }
            for (int j = i; j < count - 1; j++) {
                studentArray[j] = studentArray[j + 1];
            }
            count--;
            printf("Da xoa sinh vien ID: %d\n", id);
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien ID: %d\n", id);
    }
}

void updateStudent() {
    int id;
    printf("Nhap ID muon cap nhat: ");
    scanf("%d", &id);
    getchar(); // clear buffer
    for (int i = 0; i < count; i++) {
        if (studentArray[i].id == id) {
            printf("Nhap ten moi: ");
            fgets(studentArray[i].name, sizeof(studentArray[i].name), stdin);
            studentArray[i].name[strcspn(studentArray[i].name, "\n")] = '\0';
            printf("Nhap diem TB moi: ");
            scanf("%d", &studentArray[i].avg);
            printf("Cap nhat thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay sinh vien!\n");
}

void changeStatus() {
    int id;
    printf("Nhap ID muon doi trang thai: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (studentArray[i].id == id) {
            studentArray[i].status = !studentArray[i].status;
            printf("Trang thai moi: %s\n",
                   studentArray[i].status ? "Hoat dong" : "Khong hoat dong");
            return;
        }
    }
    printf("Khong tim thay sinh vien!\n");
}

void sortStudent() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (studentArray[i].avg > studentArray[j].avg) {
                Student temp = studentArray[i];
                studentArray[i] = studentArray[j];
                studentArray[j] = temp;
            }
        }
    }
    printf("Da sap xep theo diem TB.\n");
}

void searchStudent() {
    int id;
    printf("Nhap ID can tim: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (studentArray[i].id == id) {
            printf("Tim thay: ID: %d | Ten: %s | Diem TB: %d | Trang thai: %s\n",
                   studentArray[i].id,
                   studentArray[i].name,
                   studentArray[i].avg,
                   studentArray[i].status ? "Hoat dong" : "Khong hoat dong");
            return;
        }
    }
    printf("Khong tim thay sinh vien!\n");
}

int main() {
    int choice;
    do {
        printf("1. Them sinh vien\n");
        printf("2. Hien thi danh sach\n");
        printf("3. Xoa sinh vien\n");
        printf("4. Cap nhat sinh vien\n");
        printf("5. Doi trang thai\n");
        printf("6. Sap xep theo diem TB\n");
        printf("7. Tim kiem theo ID\n");
        printf("8. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: showStudent(); break;
            case 3: deleteStudent(); break;
            case 4: updateStudent(); break;
            case 5: changeStatus(); break;
            case 6: sortStudent(); break;
            case 7: searchStudent(); break;
            case 8: printf("Thoat\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (choice != 8);

    free(studentArray);
    return 0;
}
