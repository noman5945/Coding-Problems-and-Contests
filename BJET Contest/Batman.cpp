#include<bits/stdc++.h>
using namespace std;

int solve(string sen1,string sen2,string sen3){
    int alpha[256]={-1};
    int maxlen=0;
    set<char> seq;
    for(int i=0;i<sen1.length();i++){
        alpha[sen1[i]]=i;
    }
    for(int i=0;i<sen2.length();i++){
        if(alpha[sen2[i]]!=-1){
            seq.insert(sen2[i]);
        }
    }
    for(int i=0;i<sen3.length();i++){
        if(alpha[sen3[i]]!=-1){
            seq.insert(sen3[i]);
        }
    }
    for(auto i:seq){
        cout<<i;
        maxlen++;
    }
    return maxlen;
}

int solve2(string sen1,string sen2,string sen3){
    int l=sen1.length();
    int m=sen2.length();
    int n=sen3.length();

    int dp[l+1][m+1][n+1];
    for(int i=0;i<l;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                if(i==0||j==0||k==0){
                    dp[i][j][k]=0;
                }
                else if(sen1[i-1]==sen2[j-1] && sen1[i-1]==sen3[k-1]){
                    dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                }else{
                    dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
                }
            }
        }
    }
    return dp[l][m][n];
}

int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        string sen1,sen2,sen3;
        cin>>sen1>>sen2>>sen3;
        int ans=solve2(sen1,sen2,sen3);
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
}