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
    node(){
        this->data=0;
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
void printLinkedList(node* head){
    while(head!=NULL){
        cout<<head->data<<"--->";
        head=head->next;
    }
    cout<<endl;
}


/*
node* addTwoNumbers(node* l1, node* l2) {
    reverseListIter(l1);
    reverseListIter(l2);

    node* list1=l1;
    node* list2=l2;
    int sum1=0;
    int sum2=0;

    while(list1!=NULL){
        sum1=list1->data+sum1*10;
        list1=list1->next;
    }

    while(list2!=NULL){
        sum2=list2->data+sum2*10;
        list2=list2->next;
    }

    int sum=sum1+sum2;
    node* ans=NULL;
    //cout<<sum1<<" "<<sum2<<" "<<sum<<endl;
    int temp=sum;
    while(temp!=0){
        int num=temp%10;
        //cout<<num<<"---";
        insertAthead(ans,num);
        temp=temp/10;
    }
    reverseListIter(ans);
    return ans;
}
*/
node* addTwoNumbers(node* l1, node* l2) {
    node* dummy=new node();
    node* current=dummy;

    int carry=0;

    while(l1!=NULL || l2!=NULL){
        int val1=(l1!=NULL)?l1->data:0;
        int val2=(l2!=NULL)?l2->data:0;

        int sum=val1+val2+carry;

        carry=sum/10;
        current->next=new node(sum%10);
        current=current->next;

        if(l1!=NULL){
            l1=l1->next;
        }
        if(l2!=NULL){
            l2=l2->next;
        }
    }
    if(carry==1){
        current->next=new node(1);
    }
    return dummy->next;
}

int main(){
    node* a=NULL;
    node* b=NULL;

    insertAthead(a,3);
    insertAthead(a,4);
    insertAthead(a,2);

    insertAthead(b,4);
    insertAthead(b,6);
    insertAthead(b,5);

    node* c=addTwoNumbers(a,b);
    printLinkedList(c);

}
