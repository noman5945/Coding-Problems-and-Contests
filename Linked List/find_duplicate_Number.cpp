#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int n=nums.size();
    if(n<=1){
        return 0;
    }

}

int main(){
    vector<int> nums={3,1,3,4,2};
    int dup=findDuplicate(nums);
    cout<<dup;
}
