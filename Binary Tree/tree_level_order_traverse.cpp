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

int replaceWithSum(node* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }
    int LeftSum=replaceWithSum(root->left);
    int RightSum=replaceWithSum(root->right);

    int temp=root->data;
    root->data=LeftSum+RightSum;

    return temp+root->data;
}

int tree_height(node* root){
    if(root==NULL){
        return 0;
    }
    //post order traversal
    int LS=tree_height(root->left);
    int RS=tree_height(root->right);

    return 1+max(LS,RS);
}

int main(){
    node* root=buildTree();
    levelOrderTraverse(root);

}

