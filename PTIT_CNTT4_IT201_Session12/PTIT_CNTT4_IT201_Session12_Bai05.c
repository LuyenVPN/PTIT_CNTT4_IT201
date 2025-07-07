#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node;

node *createNode(int x) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

node *insertAtHead(node *head, int x) {
    node *newNode = createNode(x);
    if (head != NULL) {
        head->prev = newNode;
        newNode->next = head;
    }
    return newNode;
}

void printList(node *head) {
    node *temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void findMid(node *head) {
    if (head == NULL) {
        printf("Danh sach rong\n");
        return;
    }

    node *slow = head;
    node *fast = head;
    int index = 1;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        index++;
    }

    printf("Node %d: %d\n", index, slow->data);
}

int main() {
    node *head = NULL;
    int n, x;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &x);
        head = insertAtHead(head, x);
    }

    printf("Danh sach lien ket doi:\n");
    printList(head);

    findMid(head);

    return 0;
}
