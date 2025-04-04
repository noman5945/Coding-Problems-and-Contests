/**
 * Count the numbers of "Binary Search Trees" that can be formed using
 * N nodes numbered 1 - N
 * Sample Input
 *  - 3
 *  - 4
 * Output
 *  - 5
 *  - 14
 */

#include<bits/stdc++.h>
using namespace std;

int helper_count_trees(int n,vector<int> dp){
    if(n==0  || n==1){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int x=helper_count_trees(i-1,dp);
        int y=helper_count_trees(n-i,dp);
        ans+=x*y;
    }
    dp[n]=ans;
    return dp[n];
}

int helper_count_trees_bottomUp(int n,vector<int> dp){
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i]+=(dp[j-1]*dp[i-j]);
        }
    }
    return dp[n];
}

int count_trees(int N){
    vector<int> dp(N+1,-1);
    int ans=helper_count_trees(N,dp);
    int ans_2=helper_count_trees_bottomUp(N,dp);
    return ans_2;
}

int main(){
    int N;
    cin>>N;
    int ans=count_trees(N);
    cout<<ans<<endl;

}