#include<bits/stdc++.h>
using namespace std;

string solve(int a,int b,int c){
    int calc=a*a+b*b-c*c;
    if(calc==0){
        return "yes";
    }
    return "no";
}

int main(){
    int t;
    cin>>t;
    int a,b,c;
    while(t--){
        cin>>a>>b>>c;
        string ans=solve(a,b,c);
        cout<<ans<<endl;
    }
}
