#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *left;
    Node *right;

    Node(int x){
        this->val=x;
        left=NULL;
        right=NULL;
    }
};

class LinkedList{
public:
    Node* head;
    Node* tail;
};


Node* insert_node(Node* root,int key){
    if(root==NULL){
        return new Node(key);
    }

    if(root->val>=key){
        root->left=insert_node(root->left,key);
    }else{
        root->right=insert_node(root->right,key);
    }

    return root;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }

    //left,root,right

    inorder(root->left);
    cout<<root->val<<" ,";
    inorder(root->right);

    return;
}

bool search_node(Node* root,int key){
    if(root==NULL){
        return false;
    }

    if(root->val==key){
        return true;
    }
    if(key>root->val){
        return search_node(root->right,key);
    }
    else{
        return search_node(root->left,key);
    }
}

/* Create BST of Minimum height from sorted array*/
Node* create_min_BST(vector<int> &nums,int start,int en){

    if(start>en){
        return NULL;
    }

    int mid=(start+en)/2;
    Node *root = new Node(nums[mid]);

    root->left=create_min_BST(nums,start,mid-1);
    root->right=create_min_BST(nums,mid+1,en);

    return root;
}

/* find the closest node of the target*/
int find_closest_node(Node* root,int target){

    int closest;
    int diff=INT_MAX;

    Node *temp=root;

    while(temp!=NULL){
        int current_diff=abs(root->val-target);
        if(current_diff==0){
            return temp->val;
        }

        if(current_diff<diff){
            closest=temp->val;
            diff=current_diff;
        }

        if(target>temp->val){
            temp=temp->right;
        }else{
            temp=temp->left;
        }
    }

    return closest;

}

/* turn tree into linked list (flattening)*/
LinkedList BST_to_LinkedList(Node* root){
    LinkedList l;
    if(root==NULL){
        l.head=NULL;
        l.tail=NULL;

        return l;
    }

    if(root->left==NULL && root->right==NULL){
        l.head=root;
        l.tail=root;

        return l;
    }
    else if(root->left!=NULL && root->right==NULL){
        LinkedList LLleft=BST_to_LinkedList(root->left);
        LLleft.tail->right=root;

        l.head=LLleft.head;
        l.tail=root;


    }
    else if(root->left==NULL && root->right!=NULL){
        LinkedList LLright=BST_to_LinkedList(root->right);
        root->right=LLright.head;

        l.head=root;
        l.tail=LLright.tail;


    }
    else{
        LinkedList LLleft=BST_to_LinkedList(root->left);
        LinkedList LLright=BST_to_LinkedList(root->right);

        LLleft.tail->right=root;
        root->right=LLright.head;

        l.head=LLleft.head;
        l.tail=LLright.tail;


    }

     return l;
}

/* find inorder successor*/
Node* inorder_successor(Node* root,Node* target){



}

int main(){
    Node *root=NULL;
    Node *min_root=NULL;

    vector<int> datas={8,3,10,1,6,14,4,7,13};
    vector<int> sorted_datas={1,2,3,4,5,6,7};

    for(int data:datas){
        root=insert_node(root,data);
    }
    min_root=create_min_BST(sorted_datas,0,sorted_datas.size()-1);

    inorder(root);
    cout<<endl;
    inorder(min_root);
    cout<<endl;

    int num;
    cin>>num;
    bool found=search_node(root,num);
    cout<<endl;
    if(found){
        cout<<"exists"<<endl;
    }else{
        cout<<"Not exist"<<endl;
    }
}
