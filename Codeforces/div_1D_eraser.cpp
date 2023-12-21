#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    int k;
    int j=0;
    int cntB=0;

    cin>>n>>k;
    string s;
    cin>>s;

    while(j<n){
        if(s[j]=='B'){
            cntB++;
            j=j+k-1; //??
        }
        j++;
    }
    cout<<cntB<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
