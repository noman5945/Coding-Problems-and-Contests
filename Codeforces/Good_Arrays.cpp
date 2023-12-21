#include<bits/stdc++.h>
using namespace std;

string good_arrays(vector<int> &arr,int n){
    int sum_a=0;
    int count_ones=0;
    for(int num:arr){
        sum_a+=num;
        if(num==1){
            count_ones++;
        }
    }
    if(sum_a>=count_ones+n && n>1){
        return "Yes";
    }
    return "No";
}

int main(){
    int t,n;
    int in;
    string ans;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> arr;
        for(int i=0;i<n;i++){
          cin>>in;
          arr.push_back(in);
        }
     ans=good_arrays(arr,n);
     cout<<ans;
    }

}
