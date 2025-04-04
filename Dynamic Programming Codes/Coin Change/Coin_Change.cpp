/**
 * Given an Array of coin denominations and integer M representing target money,
 * Find the " min coins " required 
 * to make the change.
 * 
 * Input: coins=[1,3,7,10] , M=15
 * Output: 3
 */

#include<bits/stdc++.h>
using namespace std;

//Bottom Up approach
int minNumbersofCoinsChange(int m,vector<int> &arr){
    vector<int> dp(m+1,0);
    dp[0]=1;

    for(int i=1;i<=m;i++){
        dp[i]=INT_MAX;
        for(auto c:arr){
            if(i-c>=0 && dp[i-c]!=INT_MAX){
                dp[i]=min(dp[i],dp[i-c]+1);
            }
        }
    }

    return dp[m]==INT_MAX?-1:dp[m];
}

int main(){
    vector<int> coins={1,3,7,10};
    int m=15;
    int ans=minNumbersofCoinsChange(m,coins);
    cout<<ans<<endl;
}