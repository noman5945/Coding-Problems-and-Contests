#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int data){
        this->data=data;
        next=NULL;
    }
};

void insertAthead(node* &head,int data){
    if(head==NULL){
        head=new node(data);
        return;
    }
    //otherwise
    node* n=new node(data);
    n->next=head;
    head=n;
}

void printLinkedList(node* head){
    while(head!=NULL){
        cout<<head->data<<"--->";
        head=head->next;
    }
    cout<<endl;
}

void insertInMiddle(node* head,int data,int pos){
    if(pos==0){
        insertAthead(head,data);
    }else{
        node * temp = head;
        for(int j=1;j<=pos-1;j++){
            temp=temp->next;
        }
        node* n=new node(data);
        n->next=temp->next;
        temp->next=n;
    }
}


node* merge_lists(node* a,node *b){
    if(a==NULL){
        return b ;
    }
    if(b==NULL){
        return a;
    }

    node* c;
    if(a->data < b->data){
        c=a;
        c->next=merge_lists(a->next,b);
    }else{
        c=b;
        c->next=merge_lists(a,b->next);
    }
    return c;
}


// recursive approach takes O(N) time and O(N) space
node* reverseList(node* head){
    //base case
    if(head==NULL || head->next==NULL){
        return head;
    }
    //recursive case
    node* lastHead=reverseList(head->next);
    head->next->next=head;
    head->next=NULL;
    return lastHead;
}

// iterative approach takes O(N) time and O(1) space
void reverseListIter(node* &head){
    node* prev=NULL;
    node* current=head;
    node* temp;

    while(current!=NULL){
        //store next
        temp=current->next;
        //update the current
        current->next=prev;

        prev=current;
        current=temp;
    }
    head=prev;
    return;
}

node* kReverse(node* head,int k){
    //base case
    if(head==NULL){
        return NULL;
    }

    //reverse first K nodes
    node* prev=NULL;
    node* current=head;
    node* temp;
    int cnt=1;

    while(current!=NULL && cnt<=k){
        //store next
        temp=current->next;
        //update the current
        current->next=prev;

        prev=current;
        current=temp;
        cnt++;
    }

    if(temp!=NULL){
        head->next=kReverse(temp,k);
    }

    return prev;

}

node* midPoint(node * head){
    node* fast=head->next;
    node* slow=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

node* merge_sort(node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    node* mid=midPoint(head);

    node* a=head;
    node* b=mid->next;
    mid->next=NULL;

    a=merge_sort(a);
    b=merge_sort(b);

    return merge_lists(a,b);

}


int main(){
    node* a=NULL;
    insertAthead(a,5);
    insertAthead(a,2);
    insertAthead(a,0);
    insertAthead(a,4);
    insertAthead(a,1);
    insertAthead(a,3);

    /*node* b=NULL;
    insertAthead(b,4);
    insertAthead(b,1);
    insertAthead(b,3);
    */
    node* merged=merge_sort(a);

    printLinkedList(merged);
    //insertInMiddle(head,100,2);

    //head=reverseList(head);

    //reverseListIter(head);

    //printLinkedList(head);

    //head=kReverse(head,3);

    //printLinkedList(head);

}
