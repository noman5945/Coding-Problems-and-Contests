#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string a,b;
        int n=s.size();

        for(int i=0;i<2*n;++i){
            a+="()"[i&1];
            b+=")("[i<n];
        }
        cout<<a<<endl;
        cout<<b<<endl;
    }
}
