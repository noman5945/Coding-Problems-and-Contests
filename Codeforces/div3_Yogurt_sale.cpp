#include<bits/stdc++.h>
using namespace std;

int solve(int n,int a,int b){
    int norm=n*a;
    int prom=((n/2)*b)+((n%2)*a);
    int ans=min(norm,prom);
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){ 
        int a,b,n;
        cin>>n>>a>>b;
        cout<<solve(n,a,b)<<endl;
    }
}