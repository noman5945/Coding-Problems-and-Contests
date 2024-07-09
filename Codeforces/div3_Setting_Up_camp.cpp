#include<bits/stdc++.h>
using namespace std;

int solve(int a,int b,int c){
    int intro_tents=a;
    int extro_tents=b/3;
    int remining_extro=b%3;
    if(remining_extro>=1 && c>2){
        extro_tents++;
        c=c-2;
        int uni_tents=(c/3)+(c%3);
        return intro_tents+extro_tents+uni_tents;
    }
    return -1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int ans=solve(a,b,c);
        cout<<ans<<endl;
    }
}