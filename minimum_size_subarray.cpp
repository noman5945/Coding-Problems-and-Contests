#include<bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    
    int len=INT_MAX;
    int n=nums.size();
    int sum=0;

    sort(nums.begin(),nums.end());
    int l=0,r=0;
    
    while(r<n){
        sum+=nums[r];
        while(sum>=target){
            len=min(len,r-l+1);
            sum-=nums[l];
            l++;
        }   
        r++; 
    }
        
    return len==INT_MAX?0:len;
}

int main(){
    vector<int> nums={2,3,1,2,4,3};
    int target=7;
    cout<<minSubArrayLen(target,nums)<<endl;
}