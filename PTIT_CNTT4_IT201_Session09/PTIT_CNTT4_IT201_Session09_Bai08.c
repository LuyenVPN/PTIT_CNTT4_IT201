#include <stdio.h>
#include <stdlib.h>
// khoi tao node
typedef struct Node {
    int data;
    struct Node *next;
} Node;
// tao node moi
Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
// them o cuoi danh sach
Node* getAdd(Node * head, int value) {
    Node* newNode= createNode(value);
    if (head==NULL) {
        return newNode;
    }
    Node* current= head;
    while (current->next != NULL) {
        current= current->next;
    }
    current->next= newNode;
    return head;
}
// in node
void printList(Node* head) {
    Node* current= head;
    while (current != NULL) {
        printf(" %d -> ",current->data);
        current= current->next;
    }
    printf("NULL\n");
}


// xoa node
void removeHead(Node **head) {
    if (*head == NULL) {
        return NULL;
    }
    // xoa dau
    Node* temp= *head;
    *head= (*head) ->next ;
    free(temp);

    // xoa cuoi
    // Node* current = *head;
    // while (current->next->next != NULL) {
    //     current = current->next;
    // }
    // free(current->next);
    // current->next = NULL;
}
// xoa vi tri bat ky
Node* deleteAtPos(Node* head, int pos) {
    if (head == NULL || pos <= 0) return head;
    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* current = head;
    int count = 1;
    while (current != NULL && count < pos - 1) {
        current = current->next;
        count++;
    }
    if (current == NULL || current->next == NULL) return head;
    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}


// them o dau
void getAtHead(Node **head, int n) {
    Node* newNode= createNode(n);
    newNode ->next= *head;
    *head= newNode;
}
// them vi tri bat ky
Node *getAtPos(Node *head, int value, int pos) {
    if (pos <= 0) return head;
    Node *newNode = createNode(value);
    if (pos ==1) {
        newNode ->next =head;
        return newNode;
    }
    Node* current=head;
    int count=1;
    while (current!= NULL && count< pos-1) {
        current =current->next;
        count++;
    }
    if (current== NULL) {
        free(newNode);
        return head;
    }
    newNode->next= current->next;
    current->next=newNode;
    return head;
}
int main() {
    Node* head=NULL;
    head= getAdd(head,10);
    head= getAdd(head,15);
    head= getAdd(head,20);
    head= getAdd(head,25);
    head= getAdd(head,30);
    printList(head);
    int pos;
    printf("postition:");
    scanf("%d", &pos);
    deleteAtPos(head,pos);
    printList(head);
    return 0;
}
