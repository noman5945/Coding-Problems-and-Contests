/**
 * Given an array sequence, find the length of the " longest subsequence " of
 * such that all elements of the subsequence are " sorted " in " increasing order ".
 * 
 * Input : [50, 4, 10, 8, 30, 100]
 * Output: 4
 * Explaination : {4,8,30,100}
 */

#include<bits/stdc++.h>
using namespace std;

int longest_common_subsequence(vector<int> arr){
    int n=arr.size();
    vector<int> dp(n,1);

    int len=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i]=max(dp[i],1+dp[j]);
                len=max(len,dp[i]);
            }
        }
    }
    return len;
}

int main(){
    vector<int> nums={50, 4, 10, 8, 30, 100};
    int ans=longest_common_subsequence(nums);
    cout<<ans<<endl;
}
