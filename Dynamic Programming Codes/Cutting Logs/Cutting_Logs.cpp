/**
 * Example
 * 
 * N=8
 *
 * We need to cut the log of length N with maximum profit. Each length has a certain price.
 * index     0 1 2 3  4  5  6  7
 * length  | 1 2 3 4  5  6  7  8
 * --------------------------------
 * price   | 1 5 8 9 10 17 17 20
 * 
 * Max Profit:22
 * -------------------------------------------------------------
 * Explanantion: We cut the log having the length of 6 : 17 $
 *               Then rest of the log (8-6)=2          :  5 $
 * --------------------------------------------------------------
 *               Total price                           : 22 $
 */

#include<bits/stdc++.h>
using namespace std;

//Recursive Solution
int max_profit(int prices[],int n){
    if(n<=0){
        return 0; 
    }
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        int cut=i+1;
        int current_ans=prices[i]+max_profit(prices,n-cut);
        ans=max(ans,current_ans);
    }

    return ans;
}

//Bottom Up DP
int max_profit_dp(int *prices,int n){
    int dp[n+1];
    dp[0]=0;
    for(int len=1;len<=n;len++){
        int ans=INT_MIN;
        for(int i=0;i<len;i++){
            int cut=i+1;
            int current_ans=prices[i]+dp[len-cut];
            ans=max(current_ans,ans);
        }
        dp[len]=ans;
    }
    return dp[n];
}

int main(){
    int prices[]={1 ,5 ,8 ,9 ,10 ,17 ,17 ,20};
    int n=sizeof(prices)/sizeof(int);
    cout<<max_profit_dp(prices,n)<<endl;
}