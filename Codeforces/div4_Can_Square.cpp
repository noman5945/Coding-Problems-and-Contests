#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int sum=0;
    double root;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        sum+=a;
    }

    root=sqrt(sum);
    int int_root=root*10;
    if(int_root%10==0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}