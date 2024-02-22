#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
/*struct node
{
    char studentname[MAX];
    int marks;
    int roll_number;
    char class[MAX];
    struct node* next;
};
/*
void insertstudent(struct node**head,char name[MAX],int marks,char class[MAX],int roll_number){
    struct node* newstudent;
    newstudent=(struct node*)malloc(sizeof(struct node));
    strcpy(newstudent->studentname,name);
    newstudent->marks=marks;
    strcpy(newstudent->class,class);
    newstudent->roll_number=roll_number;
    if (head==NULL){
        head=newstudent;
    }
    newstudent->next=head;
    head=newstudent;
}

void display(struct node*head){
    struct node*temp;
    temp=head;
    while (temp!=NULL)
    {
        printf("name : %s",temp->studentname);
        printf("marks : %d",temp->marks);
        printf("class : %s",temp->class);
        printf("rollnumber : %d",temp->roll_number);
        temp=temp->next;
    } 
}
struct Student
{
    int rollnumber;
    char name[100];
    char phone[100];
    float percentage;
    struct Student *next;
    
};
struct Student * insert(struct Student *head, int rollnumber, char name[100], char phone[100], float percentage)
{
    
    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
    student->rollnumber = rollnumber;
    strcpy(student->name, name);
    strcpy(student->phone, phone);
    student->percentage = percentage;
    student->next = NULL;
    
    if(head==NULL)
    { if head is NULL, set student as the new head 
        head = student;

if list is not empty
         insert student in beginning of head 
        student->next = head;
        head = student;
    }
    
    return head;
    
}
void cdisplay(struct Student *head)
{
    struct Student * temp = head;
    while(temp!=NULL){
        
        printf("Roll Number: %d\n", temp->rollnumber);
        printf("Name: %s\n", temp->name);
        printf("Phone: %s\n", temp->phone);
        printf("Percentage: %0.4f\n\n", temp->percentage);
        temp = temp->next;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void push(int val)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void pop()
{
    struct Node *temp;

    if(head == NULL)
        printf("Stack is Empty\n");
    else
    {
        printf("Poped element = %d\n", head->data);
        temp = head;
        head = head->next;
        free(temp);
    }
}

void display()
{
    struct Node *temp = head;
    while(temp != NULL)
    {
         printf("%d->", temp->data);
         temp = temp->next;
    }
    printf("NULL\n");
}
int peek()
{
    if (head == NULL)
    {
        printf("Stack is Empty\n");
        return -1;
    }
    return head->data;
}
int main()
{
    push(10);
    push(20);
    push(30);
    printf("Linked List\n");
    peek();
    display();
    pop();
    printf("After the pop, the new linked list\n");
    display();
    pop();
    printf("After the pop, the new linked list\n");
    display();

    return 0;
}*/
struct node{
    int data;
    struct node* next;
};

int main(){


}