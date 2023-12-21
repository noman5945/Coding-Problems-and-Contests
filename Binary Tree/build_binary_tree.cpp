#include<bits/stdc++.h>
using namespace std;


class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

node* buildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }
    node* n=new node(d);
    n->left=buildTree();
    n->right=buildTree();

    return n;
}

node* buildBinaryTree(){
    int d;
    cin>>d;
    node* root=new node(d);

    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* current=q.front();
        q.pop();

        int c1,c2;
        cin>>c1>>c2;

        if(c1!=-1){
            current->left=new node(c1);
            q.push(current->left);
        }
        if(c2!=-1){
            current->right=new node(c2);
            q.push(current->right);
        }
    }
    return root;

}


void levelOrderTraverse(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp=q.front();
        if(temp==NULL){
            //this means end of a level
            cout<<endl;
            q.pop();
            //insert a new NULL for next level
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            q.pop();
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
    node* binaryRoot=buildBinaryTree();
    levelOrderTraverse(binaryRoot);
}
