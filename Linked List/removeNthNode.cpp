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
node* removeNthFromEnd(node* head, int n) {
    int s=0;
    node* prev=head;
    node* run=head;

    while(run!=NULL){
        run=run->next;
        s++;
    }
    int k=s-n;
    int i=0;
    //cout<<k<<" "<<s<<endl;
    if(s<=1){
        return NULL;
    }
    while(i<k-1){
        head=head->next;
        i++;
    }
    head->next=head->next->next;
    return prev;
}
/* neet code*/
/* if (head->next == NULL) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (n > 0) {
            fast = fast->next;
            n--;
        }

        if (fast == NULL) {
            return head->next;
        }

        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;
        return head;
*/

int main(){
    node* a=NULL;
    //insertAthead(a,5);
    //insertAthead(a,4);
    //insertAthead(a,3);
    insertAthead(a,2);
    insertAthead(a,1);
    node* h=removeNthFromEnd(a,2);
    printLinkedList(h);

}
