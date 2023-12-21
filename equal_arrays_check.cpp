#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool check(vector<ll> A, vector<ll> B, int N) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int i=0;

    while(i<N){
        if(A[i]!=B[i]){
            return false;
        }
        i++;
    }

    return true;
}

int main(){
    vector<ll> arr1={1,2,5};
    vector<ll> arr2={2,4,15};
    int n=5;
    cout<<check(arr1,arr2,n)<<endl;
}
