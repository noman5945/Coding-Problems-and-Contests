#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n=nums.size();
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(nums[i]);
    }
    int i=0;
    for(auto &numa:s){
        //cout<<nums<<" ";
        nums[i++]=numa;
    }
    for(;i<n;i++){
        nums[i]=INT_MAX;
    }
    return s.size();
}

int main(){
    vector<int> nums={0,0,1,1,1,2,2,3,3,4};
    cout<<removeDuplicates(nums)<<endl;
    for(auto n:nums){
        cout<<n<<" ";
    }
}
