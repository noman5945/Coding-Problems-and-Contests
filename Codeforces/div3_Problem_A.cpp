#include<bits/stdc++.h>
using namespace std;

void solve(){
    double a,b,c,temp;
    double ans;
    cin>>a>>b>>c;
    if(a==b){
        cout<<0<<endl;
        return;
    }if(abs(a-b)<c){
        cout<<1<<endl;
        return;
    }
    temp=((a+b)/2);
    ans=(abs(temp-b)/c);

    //cout<<temp<<endl;
    cout<<ceil(ans)<<endl;
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
