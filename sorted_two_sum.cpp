#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> ans;
    int i=0;
    int j=numbers.size()-1;

    while(i<j){
        int sum=numbers[i]+numbers[j];
        if(sum==target){
            ans.push_back(i+1);
            ans.push_back(j+1);

            break;
        }
        else if(sum>target){
            j--;
        }
        else if(sum<target){
            i++;
        }
    }
    return ans;
}

int main(){
    vector<int> nums={2,7,11,15};
    vector<int> ans;
    int target;
    cin>>target;
    ans=twoSum(nums,target);
    for(auto& x:ans){
        cout<<x<<" ,";
    }
}
