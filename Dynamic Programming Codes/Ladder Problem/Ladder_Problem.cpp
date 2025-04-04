/**
 * Problem Statement:
 * Given a ladder of size N,
 * and an integer K,
 * write a function to compute number of ways to climb the ladder 
 * if you can take " a jump of atmost  K "  at every step.
 * 
 * Input: N=4,K=3
 * Output: 7
 * 
 */

#include<bits/stdc++.h>
using namespace std;

//O(N*K)
int top_down_dp_helper(int N,int K, int *dp){
    if(N==0){
        return 1;
    }

    if(N<0){
        return 0;
    }

    if(dp[N]!=0){
        return dp[N];
    }
    int ans=0;
    for(int jump=1;jump<=K;jump++){
        ans+=top_down_dp_helper(N-jump,K,dp);
    }
    return dp[N]=ans;
}

int top_down_dp(int N,int K){
    int dp[1000]={0};
    return top_down_dp_helper(N,K,dp);

}

//Time: O(N*K)
int bottom_up_dp(int N,int K){
    vector<int> dp(N+1,0);

    dp[0]=1;
    for(int i=1;i<=N;i++){
        for(int jump=1;jump<=K;jump++){
            if(i-jump>=0){
                dp[i]+=dp[i-jump];
            }
        }
    }
    return dp[N];
}

//Time O(N)
int countWaysOptimized(int n,int k){
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;

    for(int i=2;i<=k;i++){
        dp[i]=2*dp[i-1];
    }

    for(int i=k+1;i<=n;i++){
        dp[i]=2*dp[i-1]-dp[i-k-1];
    }

    return dp[n];
}

int main(){
    int N,K;
    cin>>N>>K;
    int ans=top_down_dp(N,K);
    int ans2=bottom_up_dp(N,K);
    int optAns=countWaysOptimized(N,K);
    cout<<ans<<endl;
    cout<<ans2<<endl;
    cout<<optAns<<endl;
}