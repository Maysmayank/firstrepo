#include <iostream>
using namespace std;
#include<bits/stdc++.h>

#include <queue>
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

node* createnode(node *root){
    int data;
    cout<<"Enter the data : "<<endl;
    cin>>data;
    root=new node(data);
    if (data==-1)
    {
        return NULL;

    }
    cout<<"enter data in left of "<< data << endl;
    root->left=createnode(root->left);
    cout<<"enter data in right of "<<data<<endl;
    root->right=createnode(root->right);



}

// we use queue for this----->
void levelordertraversal(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node * temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;

            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
        cout<<temp->data<<"  ";
        if(temp->left!=NULL){
            q.push(temp->left);    }
        if(temp->right!=NULL){

            q.push((temp->right));  }
        }

    }


}
int main(){
    node* root=NULL;
    root=createnode(root);
    levelordertraversal(root);

}
