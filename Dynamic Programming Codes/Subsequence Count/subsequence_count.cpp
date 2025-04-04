/**
 * Given two strings
 * Find the number of times the "second string" occurs
 * As a "subsequence" int the "first string"
 */

#include<bits/stdc++.h>
using namespace std;

/**
 * Recursive
 */
int subsequence_count_recursive(string s1,string s2,int i,int j){
    //Base case
    if((i==-1 && j==-1) || j==-1){
        return 1;
    }
    if(i==-1){
        return 0;
    }
    
    if(s1[i]==s2[j]){
       return subsequence_count_recursive(s1,s2,i-1,j-1)+subsequence_count_recursive(s1,s2,i-1,j);
    }
    return subsequence_count_recursive(s1,s2,i-1,j);
}

/**
 * Using Dynamic Programming
 * O(s1*s2)
 */
int subsequence_count_dp(string s1,string s2){
    int i=s1.length();
    int j=s2.length();
    vector<vector<int>> dp(i+1,vector<int>(j+1));
    for(int m=0;m<=i;m++){
        dp[m][0]=1;
    }
    
    for(int m=1;m<=i;m++){
        for(int n=1;n<=j;n++){
            if(s1[m-1]==s2[n-1]){
                dp[m][n]=dp[m-1][n]+dp[m-1][n-1];
            }else{
                dp[m][n]=dp[m-1][n];
            }
        }
    }
    return dp[i][j];
}

int main(){
    string s1="ABCDCE";
    string s2="ABC";
    int i=s1.size()-1;
    int j=s2.size()-1;
    int ans=subsequence_count_dp(s1,s2);
    cout<<ans<<endl;

}