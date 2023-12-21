#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
void insertAthead(Node* &head,int data){
    if(head==NULL){
        head=new Node(data);
        return;
    }
    //otherwise
    Node* n=new Node(data);
    n->next=head;
    head=n;
}

void printLinkedList(Node* head){
    while(head!=NULL){
        cout<<head->val<<"--->";
        head=head->next;
    }
    cout<<endl;
}
//check this pls https://www.youtube.com/watch?v=5Y2EiZST97Y
Node* copyRandomList(Node* head) {

    unordered_map<Node*,Node*> hashMapNode;

    Node* runner=head;
    while(runner!=NULL){
        hashMapNode[runner]=new Node(runner->val);
        runner=runner->next;
    }

    runner=head;
    while(runner!=NULL){
        Node* node=hashMapNode[runner];
        node->next=hashMapNode[runner->next];
        node->random=hashMapNode[runner->random];
        runner=runner->next;
    }
    return hashMapNode[head];
}


int main(){
    Node* head=NULL;

    insertAthead(head,1);
    insertAthead(head,10);
    insertAthead(head,11);
    insertAthead(head,13);
    insertAthead(head,7);
    //printLinkedList(head);

}
