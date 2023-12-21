#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;

    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(abs(target-nums[i])==nums[j]){
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }
    return ans;
}

int main(){
    vector<int> nums={2,7,11,15};
    vector<int> res;

    int i=0;
    int target=9;

    res=twoSum(nums,target);
    for(int i=0;i<res.size();i++) cout<<res[i]<<" ";

}
