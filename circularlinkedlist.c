#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[100];
    char location[100];
    char degree_offered[100];
    struct Node* next;
};

struct Node* insertcollege(struct Node* head, char name[100], char location[100], char degree_offer[100]) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(newnode->name, name);
    strcpy(newnode->location,location);
    strcpy(newnode->degree_offered, degree_offer);
   if (head == NULL) 
    {
        newnode->next = newnode;
        head = newnode; 
    }
    else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
        head = newnode;
    }

    return head;

}
struct Node* delete(struct Node* head) {
    struct Node* curr=head->next;
    struct Node* prev=head;
    while (curr->next!=head)
    {   
        prev=curr;
        curr=curr->next;
    }
    prev->next=curr->next;
    curr->next=NULL;
    free(curr);
    return head;
    

}


void printList(struct Node* head) {
    printf("-----------COLLEGE INFO__________\n");

    if (head != NULL) {
        struct Node* current = head;
        do {
            printf(" College Name: %s\n College Location: %s\n Degree Offered: %s\n", current->name, current->location, current->degree_offered);
            printf("-----------------------------------------------------------------------------\n");
            current = current->next;
        } while (current != head);
    }

    printf("\n");
}

int main(){
    struct Node* head=NULL;
    head=insertcollege(head,"USICT","Dwarka","IPU");
    head=insertcollege(head,"SRCC","Delhi","DU Offered");
    head=insertcollege(head,"IIT","Delhi","IIT Offered");

    printList(head);
    printf("---------------After deleting last node -----------------\n\n");
    head=delete(head);
    printList(head);

}