#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int sum=0;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    //cout<<sum;
    int current_sum=0;
    for(int i=0;i<n;i++){
        current_sum+=arr[i];
        int rest=sum-current_sum;
        if(rest%2==0 && current_sum%2==0){
            cout<<"Yes"<<endl;
            return;
        }else if(rest%2!=0 && current_sum%2!=0){
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
    return;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
