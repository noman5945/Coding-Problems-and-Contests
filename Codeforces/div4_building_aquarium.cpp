#include<bits/stdc++.h>
using namespace std;
using li=long long;

void solve(){
    li n,x,i;
    cin>>n>>x;
    li a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }

    li lo=0;
    li hi=2000000007;

    while(lo<hi){
        li mid=(lo+(hi-lo+1))/2;
        li total=0;
        for(i=0;i<n;i++){
            total+=max(mid-a[i],0LL);
        }
        if(total<=x){
            lo=mid;
        }else{
            hi=mid-1;
        }
    }
    cout<<lo<<endl;

}

int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }
}
