#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    if(abs(a-b)==0){
        cout<<c<<endl;
        return;
    }
    if(abs(b-c)==0){
        cout<<a<<endl;
        return;
    }
    if(abs(a-c)==0){
        cout<<b<<endl;
        return;
    }
}

int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }
}