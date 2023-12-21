#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    /*
    int cnt=0;
    int start=0;
    int en=0;
    int range=0;
    int longer=INT_MIN;
    int n=nums.size();
    sort(nums.begin(),nums.end());

    for(int i=0;i<=n-1;i++){
        if(abs(nums[i+1]-nums[i])>1){
            en=i;
            range=en-start+1;
            longer=max(longer,range);
            start=en+1;
        }
        if(abs(nums[i+1]-nums[i])<1){
            cnt++;
        }
    }
    if(cnt==n){
        return cnt;
    }
    return longer;
    */

    unordered_set<int> s(nums.begin(),nums.end());
    int longest=0;
    for(auto &x:s){
        if(!s.count(x-1)){
            int length=1;
            while(s.count(x+length)){
                ++length;
            }
            longest=max(longest,length);
        }
    }
    return longest;
}

int main(){
    vector<int> nums={0,3,7,2,5,8,4,6,0,1};
    int longer=longestConsecutive(nums);
    cout<<longer<<endl;
}
