#include<bits/stdc++.h>
using namespace std;
using li = long long;

void solve(){
    long long n,ain,bin,sumA=0,sumB=0,sum=0;
    cin>>n;
    vector<li> a;
    vector<li> b;
    long long min_1=INT_MAX;
    long long min_2=INT_MAX;
    for(int i=0;i<n;i++){
        cin>>ain;
        a.push_back(ain);
        min_1=min(ain,min_1);
        sumA+=a[i];
    }
    for(int i=0;i<n;i++){
        cin>>bin;
        b.push_back(bin);
        min_2=min(bin,min_2);
        sumB+=b[i];
    }
    long long temp1=min_1*n+sumB;
    long long temp2=min_2*n+sumA;
    sum=min(temp1,temp2);

    cout<<sum<<endl;;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }
}
