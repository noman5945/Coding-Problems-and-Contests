#include<bits/stdc++.h>
using namespace std;

int calc_profit_resursive_sol(vector<int> prices,int left,int right,int year){
    if(left>right){
        return 0;
    }
    int pick_left=prices[left]*year+calc_profit_resursive_sol(prices,left+1,right,year+1);
    int pick_right=prices[right]*year+calc_profit_resursive_sol(prices,left,right-1,year+1);
    int ans=max(pick_left,pick_right);
    return ans; 
}

int calc_profit_dp_sol(vector<vector<int>>dp,vector<int> prices,int left,int right,int year){
    if(left>right){
        return 0;
    }
    if(dp[left][right]!=0){
        return dp[left][right];
    }
    int pick_left=prices[left]*year+calc_profit_dp_sol(dp,prices,left+1,right,year+1);
    int pick_right=prices[right]*year+calc_profit_dp_sol(dp,prices,left,right-1,year+1);
    dp[left][right]=max(pick_left,pick_right);
    return dp[left][right];
}

int calculate_maximum_profit(vector<int> prices){
    int left=0,right=prices.size()-1;
    int year=1;
    vector<vector<int>> dp(right+1,vector<int>(right+1,0));
    //int ans=calc_profit_resursive_sol(prices,left,right,year);
    int ans_dp=calc_profit_dp_sol(dp,prices,left,right,year);
    return ans_dp;
}

int main(){
    vector<int> prices={2,3,5,1,4};
    int ans=calculate_maximum_profit(prices);
    cout<<ans<<endl;
}