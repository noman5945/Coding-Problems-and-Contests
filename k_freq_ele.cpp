#include<bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> ans;
    unordered_map<int,int> mp;
    int n=nums.size();
    int j=0;
    vector<int> freq(n+1,-1);

    if (k == nums.size()) {
        return nums;
    }

    for(int i=0;i<nums.size();i++){
        //cout<<"gotchu 1"<<endl;
        mp[nums[i]]++;
    }

    for (auto i : mp){
        //cout<<i.second<<"  "<<i.first<<endl;
        freq[i.second]=i.first;
    }
    //&& k>0
    for(int i=n;i>=0 && k>0;i--){
        //cout<<freq[i]<<endl;
        if(freq[i]!=-1){
            ans.push_back(freq[i]);
            k--;
        }

    }

    return ans;
}

int main(){
    vector<int> freq;
    vector<int> nums={4,1,-1,2,3};
    int k=2;
    freq=topKFrequent(nums,k);
    for(int i=0;i<freq.size();i++){
        cout<<freq[i]<<",";
    }
}
