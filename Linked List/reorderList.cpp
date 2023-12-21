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

node* merge_lists(node* a,node *b){
    /*
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
    */
    while(a!=NULL){
        node* p1 = a->next;
        node* p2 = b->next;

        a->next = b;
        if (p1 == NULL) {
            break;
        }
        b->next = p1;

        a = p1;
        b = p2;
    }
    return a;
}

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

void reorderList(node* head) {

    node* prev=NULL;
    node* slow=head;
    node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    prev->next=NULL;

    reverseListIter(slow);
    //printLinkedList(slow);
    node* l1=head;
    head=merge_lists(l1,slow);

}

int main(){
    node* a=NULL;
    insertAthead(a,5);
    insertAthead(a,4);
    insertAthead(a,3);
    insertAthead(a,2);
    insertAthead(a,1);
    //printLinkedList(a);
    reorderList(a);
    printLinkedList(a);
}
