#include<bits/stdc++.h>
using namespace std;

void solve(){
    int t;
    cin>>t;
    while(t--){
        int n,s[109],e[109];
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>s[i]>>e[i];
        }
        bool can=true;

        for(int i=1;i<n;i++){
            if(s[i]>=s[0] && e[i]>=e[0]){
                can=false;
            }
        }

        if(can==false){
            puts("-1");
            continue;
        }
        cout<<s[0]<<endl;
    }
}

int main(){
    solve();
}
