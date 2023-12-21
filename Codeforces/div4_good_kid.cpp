#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin>>t;
    int min_1=INT_MAX,idx=0,prod=1;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        prod=1;
        for(int i=0;i<n;i++){
            cin>>a[i];

        }
        sort(a,a+n);
        a[0]++;
        for(int i=0;i<n;i++){
            prod*=a[i];
        }

        cout<<prod<<endl;
    }
}

