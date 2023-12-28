#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n=3;
    char latin[n][n];
    char a,b,c;
    int track=0;
    
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        latin[i][0]=a;
        latin[i][1]=b;
        latin[i][2]=c;
    }

    for(int i=0;i<n;i++){
        int alpha_sum=6;
        int temp_sum=0;
        for(int j=0;j<n;j++){
            if(latin[i][j]!='?'){
                temp_sum+=(latin[i][j]-'A')+1;
            }
        }
        if(alpha_sum>temp_sum){
            char ans=65+(alpha_sum-temp_sum)-1;
            cout<<ans<<endl;

        }
    }
}

int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }
}