#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack{
    int data;
    struct stack* next; 
};

void push(struct stack** top, int value) {
    struct stack* newnode = (struct stack*)malloc(sizeof(struct stack));
    if (newnode == NULL) {
        printf("ERROR!!\n");
    }
    
    newnode->data = value;

    newnode->next = *top;
    *top = newnode;
}
int pop(struct stack** top) {
    if (*top == NULL) {
        printf("Stack Underflow: The stack is empty.\n");
    }

    struct stack* temp = *top;
    int poppedValue = temp->data;
    *top = temp->next;
    free(temp);
    return poppedValue;
}


void traverse(struct stack *top){
    struct stack *temp;
    temp=top;
    if (top==NULL){
        printf("stack is empty\n");
    }
    else{
        while (temp!=NULL)
        {
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
        
    }
}
int peek(struct stack* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        exit(EXIT_FAILURE);
    }

    return top->data;
}

int main(){
    struct stack* top=NULL;
    push(&top,111);
    push(&top,0);
    push(&top,07);
    push(&top,105);
    traverse(top);
    int poppedvalue=pop(&top);
    printf("------after popping the element-------\n\n");
    printf("popped element is %d \n",poppedvalue);
    traverse(top);
    int peekval=peek(top);
    printf("peeked value is %d \n",peekval);
    


}