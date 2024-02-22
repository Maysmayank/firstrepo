#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queue {
    int data;
    struct queue* next;
};

void enqueue(struct queue** front, struct queue** rear, int value) {
    struct queue* newnode;
    newnode = (struct queue*)malloc(sizeof(struct queue));
    if (newnode == NULL) {
        printf("Overflow\n");
        return;
    }
    newnode->data = value;
    newnode->next = NULL;

    if (*front == NULL) {
        *front = newnode;
        *rear = newnode;
    } 
    else {
        (*rear)->next = newnode;
        *rear = newnode;
    }
}
int dequeue( struct queue** front, struct queue** rear){
    if(*front==NULL){
        printf("underflow\n");
    }
    struct queue* temp=*front;
    int value=temp->data;
    *front=(*front)->next;
    temp->next=NULL;
    free(temp);
    return value;

}
void display(struct queue* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    while (front != NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

int main() {
    struct queue* front = NULL;
    struct queue* rear = NULL;
    enqueue(&front, &rear, 71);
    enqueue(&front, &rear, 121);
    enqueue(&front, &rear, 3000);
    enqueue(&front, &rear, 405);
    enqueue(&front, &rear, 507);
    enqueue(&front, &rear, 641);
    display(front);
    int deleteval=dequeue(&front,&rear);
    printf("Deleted item is : %d\n",deleteval);
    display(front);

    return 0;
}
