#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long int x;
    cin>>x;
    long long int a=x;
    long long int dig;
    while(a!=0){
        dig=a%10;
        cout<<dig<<endl;
        a=a/10;
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

