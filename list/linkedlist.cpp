#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
    ~node() {
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
    }
};

// Circular linked list

void insertnodeincll(node*& tail, int data, int element) {
    if (tail == NULL) {
        node* newnode = new node(data);
        tail = newnode;
        newnode->next = newnode;
    }
    else {
        node* curr = tail;
        while (curr->data != element) {
            curr = curr->next;
            if (curr == tail) {
                cout << "Element " << element << " not found in the list." << endl;
                return;
            }
        }
        node* nodetoinsert = new node(data);
        nodetoinsert->next = curr->next;
        curr->next = nodetoinsert;
    }
}

void printcll(node* tail) {
    if (tail == NULL) {
        cout << "Empty list." << endl;
        return;
    }
    node* temp = tail;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl;
}

void deletecll(node * &tail,int value){
    if(tail==NULL){
        cout<<"empty list";
    }
    else{
        node* prev=tail;
        node* curr=prev->next;
        while (curr->data!=value)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        if(tail==curr){
            tail=curr->next;
        }
        curr->next=NULL;
        delete curr;
    }
}
int main() {
    node* tail = NULL;
    insertnodeincll(tail, 1, 4);
    insertnodeincll(tail,2,1);
    insertnodeincll(tail,3,2);
    insertnodeincll(tail,456,2);
    printcll(tail);
    deletecll(tail,1);
    printcll(tail);
    return 0;
}
