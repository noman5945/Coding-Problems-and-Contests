#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    
    int j=0;
    int count=0;
    int n=nums.size();
    unordered_map<int,int> num_freq;
    while(j<n){
        num_freq[nums[j]]++;
        if(num_freq[nums[j]]>2){
            nums[j]=INT_MAX;
            count++;
        }
        j++;
    }
    sort(nums.begin(),nums.end());
    return n-count;
}

int main(){
    vector<int> nums={0,0,1,1,1,1,2,3,3};
    cout<<removeDuplicates(nums)<<endl;
    for(auto n:nums){
        cout<<n<<" ";
    }
}
