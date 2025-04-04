/**
 * Given weights and prices of n items
 * we need put a subset of items of bag capacity W
 * SUCH THAT we get MAXIMUM VALUE in the bag.
 * 
 * Input
 * 
 * N=4 W=11
 * wts=[2,7,3,4]
 * prices=[5,20,20,10]
 * 
 * Output
 * 40
 */

#include<bits/stdc++.h>
using namespace std;

int knapsack_recursion(vector<int> weights,vector<int> prices,int N,int W){
    if(N==0 || W==0){
        return 0;
    }
    int remaining_weight=W-weights[N-1];
    int include_item=0,exclude_item=0;
    if(weights[N-1]<=W){
        include_item=prices[N-1]+knapsack_recursion(weights,prices,N-1,remaining_weight);
    }
    exclude_item=knapsack_recursion(weights,prices,N-1,W);
    return max(include_item,exclude_item);
}

/**
 * Bottom UP DP
 * Notice this: the base case is alwasys at [0][0] of dp array
 */
int knaspsack_DP(vector<int> weights,vector<int> prices,int N,int W){
    vector<vector<int>> dp(N+1,vector<int>(W+1,0));

    for(int n=1;n<=N;n++){
        for(int w=1;w<=W;w++){
            int inc=0,exc=0;
            int remaining_weight=w-weights[n-1];
            if(weights[n-1]<=w){
                inc=prices[n-1]+dp[n-1][remaining_weight];
            }
            exc=dp[n-1][w];
            dp[n][w]=max(inc,exc);
        }
    }

    return dp[N][W];
}

int main(){
    int N=4 ,W=11;
    vector<int> wts={2,7,3,4};
    vector<int> prices={5,20,20,10};
    int ans=knaspsack_DP(wts,prices,N,W);
    cout<<ans<<endl;
}