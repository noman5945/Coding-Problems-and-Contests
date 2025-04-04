#include<bits/stdc++.h>
using namespace std;

string solve(long int w){
    long int start=0;
    long int end=w;
    vector<pair<int,int>> anses;
    while (start<=end){
        long int mid=(end+start)/2;
        long int num2=w/mid;
        if(mid%2==0 && num2%2!=0){
            
        }
    }
    
}

int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        long int w;
        cin>>w;
        
        cout<<"Case "<< i+1<<": "<<solve(w)<<endl;
    }
}