/**
 * Question:
 * 
 * N stones given as an 'array', 
 * each element in array is the height of stone
 * Initially Frog is on Stone 1
 * The following action will be done for some number of rimes to reach Stone N
 *  
 *  **-> If the frog is currently on Stone i, jump to Stone i+1 or Stone i+2. Here, a cost of |hi-hj| is incurred, where j is the stone to land on
 * Find the " Minimum possible total cost " incurred before the frog reaches Stone NN
 *   
 * Input : 6
 * 30 10 60 10 60 50
 * 1  2  3  4  5  6
 * Output : 40
 * (by following path 1->3->5->6)
 * |30-60|+|60-60|+|60-50|=40
*/

#include<bits/stdc++.h>
using namespace std;

int min_cost(vector<int> arr,vector<int> dp,int n,int i){
    dp[1]=abs(arr[0]-arr[1]);

    for(int i=2;i<n;i++){
        int op1=abs(arr[i]-arr[i-1])+dp[i-1];
        int op2=abs(arr[i]-arr[i-2])+dp[i-2];
        dp[i]=min(op1,op2);
    }
    return dp[n-1];
}
int main(){
    vector<int> arr={30, 10, 60, 10, 60, 50};
    int n=arr.size();
    vector<int> dp(n,0);
    int ans=min_cost(arr,dp,n,0);
    cout<<ans<<endl;
}