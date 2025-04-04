/**
 * Given an array of positive integers, where "each element" represents 
 * "the max no. of steps" you can jump forward in the array.
 * Find "minimum jumps" needed to reach the "final index."
 * 
 * Input : arr=[3,4,2,1,2,3,7,1,1,1,2,5]
 * Output : 4
 */

#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> arr,int n,vector<int> dp,int i){
    if(i==n-1){
        return 0;
    }
    if(i>=n){
        return INT_MAX;
    }
    if(dp[i]!=0){
        return dp[i];
    }
    int steps=INT_MAX;
    int max_jump=arr[i];
    for(int jump=1;jump<=max_jump;jump++){
        int next_cell=i+jump;
        int sub_problem=solution(arr,n,dp,next_cell);
        if(sub_problem!=INT_MAX){
            steps=min(steps,sub_problem+1);
        }
    }
    dp[i]=steps;
    return dp[i];
}

int main(){
    vector<int> arr;
    int n,num;
    vector<int> dp(n,0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        arr.push_back(num);
    }
    int ans=solution(arr,n,dp,0);
    cout<<ans<<endl;
}