#include<bits/stdc++.h>
using namespace std;

bool ok(string s){
    for(size_t i=1;i<s.length();++i){
        if(s[i]==s[i-1]){
            return false;
        }
    }
    return true;
}

void solve(){
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s;
    cin>>t;
    
    if(ok(s)){
        cout<<"YES"<<endl;
        return;
    }   

    if(!ok(t)|| *t.begin()!=*t.rbegin()){
        cout<<"NO"<<endl;
        return;
    }

    int zz=0,oo=0;
    for(size_t i=1;i<s.length();++i){
        if(s[i]==s[i-1]){
            if(s[i]=='1'){
                oo=true;
            }
            if(s[i]=='0'){
                zz=true;
            }
        }
    }

    if(zz && t[0]=='0'){
        cout<<"NO"<<endl;
        return;
    }
    if(oo && t[0]=='1'){
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
    return;

}


int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
}