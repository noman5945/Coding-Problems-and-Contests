#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string lcp="";
    int n=strs.size()-1;
    sort(strs.begin(),strs.end());
    string first=strs[0];
    string last=strs[n];

    for(int i=0;i<min(first.size(),last.size());i++){
        if(first[i]!=last[i]){
            return lcp;
        }
        lcp+=first[i];
    }

    return lcp;
}

int main(){
    vector<string> strs={"flower","flow","flight"};
    cout<<longestCommonPrefix(strs)<<endl;
}
