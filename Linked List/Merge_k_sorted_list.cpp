#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(lists.size()==0){
            return NULL;
        }
        ListNode newNode=new ListNode();
        newNode=lists[0];
        for(int i=1;i<n;i++){

        }
}

int main(){

}
