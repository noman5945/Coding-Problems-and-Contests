#include<bits/stdc++.h>
using namespace std;

int count_calcs(vector<int> &arr){
    int maxu=0;
    int n=arr.size()-1;
    int index=0;
    int i=0;
    for(i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            maxu=max(maxu,arr[i]);
        }
    }
    return maxu;
}

int main(){
    int t,n;
    int in,cnt;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> arr;
        for(int i=0;i<n;i++){
          cin>>in;
          arr.push_back(in);
        }
     cnt=count_calcs(arr);
     cout<<cnt;
    }

}
