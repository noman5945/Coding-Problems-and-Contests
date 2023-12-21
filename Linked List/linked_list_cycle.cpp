#include<bits/stdc++.h>
using namespace std;
class ListNode{
public:
    int data;
    ListNode* next;

    ListNode(int data){
        this->data=data;
        next=NULL;
    }
};

bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        unordered_map<ListNode*,ListNode*> hashMapNode;

        ListNode* copy=head;
        while(copy!=NULL){

            if(hashMapNode.find(copy->next)==hashMapNode.end()){
                hashMapNode[copy->next]=copy;
            }else{
                return true;
            }

            copy=copy->next;
        }

        return false;

}
int main(){

}
