#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

typedef struct Task {
    int id;
    char title[50];
    int priority;
    char deadline[20];
}Task;

typedef struct SNode {
    Task task;
    struct SNode* next;
}SNode;

typedef struct DNode {
    Task task;
    struct DNode* next;
    struct DNode* prev;
}DNode;

SNode *singleHead=NULL;
DNode *doubleHead=NULL;
int currentID=1;
SNode *createSNode(Task task) {
    SNode *newSNode=(SNode*)malloc(sizeof(SNode));
    newSNode->task=task;
    newSNode->next=NULL;
    return newSNode;
}
SNode *addTask(SNode *head, Task task) {
    SNode *newNode=createSNode(task);
    if (head==NULL) {
        head=newNode;
        return head;
    }
    SNode *temp=head;
    while (temp->next!= NULL) {
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}
void displayTask(SNode *head) {
    if (head== NULL) {
        printf("Chua co nhiem vu\n");
        return;
    }
    SNode *temp=head;
    while (temp != NULL) {
        printf("Id: %d | Tieu De: %s | Muc do uu tien: %d | Deadline: %s \n", temp->task.id, temp->task.title, temp->task.priority, temp->task.deadline);
        temp=temp->next;
    }
}
SNode *deleteTask(SNode *head, int id) {
    SNode *temp=head;
    SNode *prev=NULL;
    while (temp!=NULL && temp->task.id!= id) {
        prev=temp;
        temp=temp->next;
    }
    if (temp==NULL) {
        printf("khong thay\n");
        return head;
    }
    if (prev== NULL) {
        head=temp->next;
    }else {
        prev->next=temp->next;
    }
    free(temp);
    return head;
}
void *updateTask(SNode *head, int id) {
    if (head==NULL) {
        printf("chua co nhiem vu");
        return;
    }
    SNode *temp=head;
    while (temp != NULL && temp->task.id != id) {
        temp=temp->next;
    }
    if (temp==NULL) {
        printf("khong tim thay id");
        return;
    }
    printf("Id: %d | Tieu De: %s | Muc do uu tien: %d | Deadline: %s \n", temp->task.id, temp->task.title, temp->task.priority, temp->task.deadline);
    printf("Tieu de moi: ");
    gets(temp->task.title);
    fflush(stdin);
    printf("Muc do uu tien: ");
    scanf("%d",&temp->task.priority);
    fflush(stdin);
    printf("Deadline: ");
    gets(temp->task.deadline);
    fflush(stdin);
}
void sortTask(SNode *head) {
    if (head== NULL) {
        printf("chua co nhiem vu");
        return;
    }
    for (SNode *i=head; i->next != NULL; i= i->next) {
        for (SNode *j=i->next; j != NULL; j= j->next) {
            if (i->task.priority > j->task.priority) {
                Task temp= i->task;
                i->task= j->task;
                j->task= temp;
            }
        }
    }
}
void sreachTask(SNode *head, char *sreach) {
    if (head==NULL) {
        printf("chx co nhiem vu");
        return;
    }
    SNode *temp=head;
    int found=0;
    while (temp!=NULL) {
        if (strstr(temp->task.title,sreach)) {
            printf("Id: %d | Tieu De: %s | Muc do uu tien: %d | Deadline: %s \n", temp->task.id, temp->task.title, temp->task.priority, temp->task.deadline);
            found=1;
        }
        temp=temp->next;
    }
    if (found==0) {
        printf("khong thay");
        return;
    }
}

DNode *createDNode(Task task) {
    DNode *newDNode=(DNode*)malloc(sizeof(DNode));
    newDNode->task=task;
    newDNode->next=NULL;
    newDNode->prev=NULL;
    return newDNode;
}

void menu() {
    int choice;
    do {
        printf("\n >>>>>>>>>>>MENU<<<<<<<<<<<\n");
        printf("1. Them nhiem vu\n");
        printf("2. Hien thi nhiem vu\n");
        printf("3. Xoa nhiem vu\n");
        printf("4. Cap nhat thong tin nhiem vu\n");
        printf("5. Danh dau nhiem vu hoan thanh\n");
        printf("6. Sap xep nhiem vu\n");
        printf("7. Tim nhiem vu\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d",&choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                Task newTask;
                newTask.id=currentID++;
                fflush(stdin);
                printf("Nhap tieu de: ");
                gets(newTask.title);
                fflush(stdin);
                printf("Muc do uu tien: ");
                scanf("%d",&newTask.priority);
                fflush(stdin);
                printf("Deadline: ");
                gets(newTask.deadline);
                fflush(stdin);
                singleHead=addTask(singleHead, newTask);
                break;
            case  2:
                displayTask(singleHead);
                break;
            case 3:
                displayTask(singleHead);
                int id;
                printf("Nhap id can xoa:");
                scanf("%d", &id);
                singleHead=deleteTask(singleHead,id);
                break;
            case 4:
                int idUpdate;
                printf("Nhap id can cap nhat:");
                scanf("%d", &idUpdate);
                fflush(stdin);
                updateTask(singleHead,idUpdate);
                break;
            case 5:
                break;
            case 6:
                printf("Truoc khi sap xep:\n");
                displayTask(singleHead);
                sortTask(singleHead);
                printf("Sau khi sap xep:\n");
                displayTask(singleHead);
                break;
            case 7:
                char sreach[50];
                printf("Nhap nhiem vu can tim:");
                gets(sreach);
                fflush(stdin);
                sreachTask(singleHead,sreach);
                break;
            case 8:
                printf("Thoat chuong trinh.");
                return;
                default:
                printf("Lua chon khong hop le.\n");
        }
    }while (choice != 8);
}
int main() {
    menu();
    return 0;
}