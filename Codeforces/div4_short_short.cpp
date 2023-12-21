#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    string sen;

    while(t--){
        cin>>sen;
        bool dec=false;
        for(int i=0;i<sen.size();i++){
            int order=sen[i]-'a';
            if(order==i){
                dec=true;
                break;
            }
        }
        if(dec==true){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
    }
}
