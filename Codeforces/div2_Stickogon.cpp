#include<bits/stdc++.h>
using namespace std;

int solve(){
    int n,num;
    vector<int> a;
    unordered_map<int,int> freq;
    int gons=0;

    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>num;
        a.push_back(num);
        freq[num]++;
    }
    
    for(auto i=freq.begin();i!=freq.end();i++){
        if(i->second>=3){
            gons++;
        } 
    }
    return gons;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
}