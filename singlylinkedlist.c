#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[100];
    int Emp_id;
    char dept[100];
    int phone_num;
    struct Node* next;
};

struct Node* insertemployee(struct Node* head, char name[100], int emp_id, char dept[100], int phone_number) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory allocation failed.");
        return head;
    }

    strcpy(newnode->name, name);
    newnode->Emp_id = emp_id;
    strcpy(newnode->dept, dept);
    newnode->phone_num = phone_number;

    newnode->next = head;

    head = newnode;
    return head;
}

void printList(struct Node* head) {
    printf("-----------employee data__________\n");

    while (head != NULL) {
        printf(" employee Name : %s\n Emp ID:%d\n Department : %s\n phone Number : %d\n",
               head->name, head->Emp_id, head->dept, head->phone_num);
        printf("-----------------------------------------------------------------------------\n");
        head = head->next;
    }
    printf("\n");
}

struct Node* deleteEmployee(struct Node* head) {
    if (head == NULL) {
        printf("Employee database is empty.\n");
        return NULL;
    }

    struct Node* last = head;
    struct Node* prev = NULL;

    while (last->next != NULL) {
        prev = last;
        last = last->next;
    }

    if (prev != NULL) {
        prev->next = NULL;
    } else {
        head = NULL;
    }

    free(last);
    return head;
}

int main() {
    struct Node* head = NULL;
    head = insertemployee(head, "Mayank", 1001, "software Dept", 458912004);
    head = insertemployee(head, "Seema", 1002, "sales dept", 784454164);
    head = insertemployee(head, "Rashmi", 1003, "Manager dept", 784454164);

    printList(head);
    printf("-----------after deletion________________\n");
    head = deleteEmployee(head);
    printList(head);

    return 0;
}
