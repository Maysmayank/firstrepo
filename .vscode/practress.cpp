#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#include<stack>
#include <queue>
/*class node{
    public:
    int data;
    node * left;
    node *right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* createnode(){
    int data;
    cout<<" Enter the data : ";
    cin>>data;
    node *root=new node(data);
    if(data==-1){
        return NULL;         // consider it as base case

    }

    cout<<"Enter data in the left of  "<< data<<endl;  
    root->left=createnode();
    cout<<"Enter data in the right of "<< data<<endl;  
    root->right=createnode();

}
void levelordertraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node* temp=q.front();
        q.pop();
        if(temp==NULL){

            cout<<endl;
            if(!q.empty()){
                q.push(NULL);

            }
        }
        else{
        cout<<temp->data<<" ";

        if(temp->left!=NULL){
            q.push(temp->left);

        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
        }
    }
    

}
int main(){
    node* root=NULL;
    root=createnode();
    levelordertraversal(root);
    
}*/

class node{
    public:
    int data;
    node * left;
    node *right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* createnode(){
    int data;
    cout<<" Enter the data : ";
    cin>>data;
    node *root=new node(data);
    if(data==-1){
        return NULL;         // consider it as base case

    }

    cout<<"Enter data in the left of  "<< data<<endl;  
    root->left=createnode();
    cout<<"Enter data in the right of "<< data<<endl;  
    root->right=createnode();

}

void reverselvltraversal(node *root){
    stack <node*> s;
    queue <node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node*temp=q.front();
        q.pop();
        if(temp==NULL){
            s.push(NULL);
            if(!q.empty()){              
                q.push(NULL);
            }
        }

        else{   
            s.push(temp);      

            if(temp->left!=NULL){
                q.push(temp->left);
                }
            if(temp->right!=NULL){
                q.push(temp->right);    }
        
        }
    }

  while (!s.empty()) {
        node* curr = s.top();
        s.pop();                        //      did a mistake pop should be placed here not after else{}

        if (curr == NULL) {
            cout << endl;
        } else {
            cout << curr->data << "  ";
        }
    }
}

int main(){
    node* root=NULL;
    root=createnode();
    reverselvltraversal(root);

}
