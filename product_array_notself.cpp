#include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int ans=1;

    int zeroCnt=count(nums.begin(),nums.end(),0);
    for(auto x:nums){
        if(x){
            ans*=x;
        }
    }
    for(auto& x:nums){
        if(zeroCnt){
            x=x?0:ans;
        }else{
            x=ans/x;
        }
    }
    return nums;
}

int main(){
    vector<int> numbers={-1,1,0,-3,3};
    vector<int> ans;
    ans=productExceptSelf(numbers);
    for(int x:ans){
        cout<<x<<", ";
    }
}
