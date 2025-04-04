/**
 * Given an array of positive integers. Find the maximum sum
 * input : 6 10 12 9 14
 * output: 32
 */

#include<bits/stdc++.h>
using namespace std;

int max_adj_sum(vector<int> nums,int n){
    vector<int> dp(n,0);
    dp[0]=nums[0];
    dp[1]=nums[1];
    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
    }

    return dp[n-1];
}

//Bottom up dp approach
// much better code
int maxSubsetSumNoAdjacent(vector<int> nums){
    int n=nums.size();
    vector<int> dp(n+1,0);
    
    //corner case
    if(n==1){
        return max(nums[0],0);
    }
    if(n==2){
        return max(0,max(nums[0],nums[1]));
    }

    dp[0]=max(nums[0],0);
    dp[1]=max(0,max(nums[0],nums[1]));

    for(int i=2;i<n;i++){
        int inc=nums[i]+dp[i-2];
        int exc=dp[i-1];
        dp[i]=max(exc,inc);
    }

    return dp[n-1];
}


int main(){
    vector<int> num={6,10,12,7,9,14};
    int n=num.size();
    int ans=maxSubsetSumNoAdjacent(num);
    cout<<ans<<endl;
}