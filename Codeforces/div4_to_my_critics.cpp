#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,a,b,c;
    cin>>t;

    while(t--){
        cin>>a>>b>>c;
        int num1=max(a,max(b,c));
        int num2=min(a,min(b,c));

        if(num1+num2>=10){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}
