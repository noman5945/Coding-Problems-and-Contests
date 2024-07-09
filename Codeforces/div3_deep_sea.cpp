#include<bits/stdc++.h>
using namespace std;
class Comparator{
public:
    bool operator()(long long int a,long long int b){
        return a<b;
    }
};
void solve(){
    long long int n,k,num;
    cin>>n>>k;
    priority_queue<long long int,vector<long long int>,greater<int>> heap;
    for(long long int i=0;i<n;i++){
        cin>>num;
        heap.push(num);
    }
    while(k--){
        long long int goat=heap.top();
        heap.pop();
        goat--;
        if(goat>0){
            heap.push(goat);
        }
    }
    cout<<abs(heap.size()-n)<<endl;
}

int main(){
    long long int t;
    cin>>t;
    while(t--){
        solve();
    }
}