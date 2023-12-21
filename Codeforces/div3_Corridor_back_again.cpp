#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int ans=INT_MAX;
    while(n--){
        int d,s;
        cin>>d>>s;
        ans=min(ans,d+((s-1)/2));
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    while(t--){
        solve();
    }
}
