#include<bits/stdc++.h>
using namespace std;

int main(){
    int w;
    cin>>w;

    int i=2;
    int rest;
    int flag=0;
    while(i<w){
        rest=w-i;
        if(rest%2==0 && i%2==0){
            flag=1;
            break;
        }
        i+=2;
    }
    if(flag){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}
