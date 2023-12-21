#include<bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    vector<int> ans;
    int n=digits.size();
    int i=0;
    while(i<n-1){
        ans.push_back(digits[i]);
    }
    return ans;
}

int main(){
    vector<int> dig={4,3,2,1};
    vector<int> ans;
    ans=plusOne(dig);
    for(auto x:ans){
        cout<<x<<" ,";
    }
}
