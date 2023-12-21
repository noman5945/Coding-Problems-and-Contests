#include<bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long i=0;
        long n=nums.size();

        while(i<n){
            if(nums[i]==nums[i+1]){
                return true;
            }
            i++;
        }
        return false;
}
int main(){
    vector<int> ques={1,2,3,4};
    if(containsDuplicate(ques)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}
