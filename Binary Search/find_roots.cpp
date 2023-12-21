#include<bits/stdc++.h>
using namespace std;

double root(int N,int P){
    int st=0;
    int en=N;
    double ans=0;

    // Find Integer part (Binary part)
    while(st<=en){
        int mid=(st+en)/2;
        if(mid*mid==N){
            return mid;
        }
        else if(mid*mid>N){
            en=mid-1;
        }
        else{
            st=mid+1;
            ans=mid;
        }
    }

    //Find Fraction part of P digits (Linear search)
    double inc=0.1;
    for(int place=1;place<=P;place++){
        while(ans*ans<=N){
            ans+=inc;
        }

        ans=ans-inc;
        inc=inc/10.0;
    }

    return ans;
}

int main(){
    int n,p;
    cin>>n>>p;
    cout<<root(n,p)<<endl;
}
