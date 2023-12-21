#include<bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int low=INT_MAX;
    int sum;
    int j;
    int diff;
    int ans=0;

    sort(nums.begin(),nums.end());

    for(int i=0;i<=nums.size()-1;i++){
        int j=i+1;
        int k=nums.size()-1;
        while(j<k){
            sum=nums[i]+nums[j]+nums[k];
            diff=abs(sum-target);
            if(sum==target){
                return sum;
            }
            //check this logic to get the closest one
            if(diff<low){
                low=diff;
                ans=sum;
            }
            //check up
            if(sum<target){
                j++;
            }else{
                k--;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> nums={-1,2,1,-4};
    int target=1;
    int ans=threeSumClosest(nums,target);
    cout<<ans<<endl;
}
