#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int i=0;
        int j=0;
        int idx[256]={-1};
        int len=0;


        while(j<n){
            if(idx[s[j]]!=-1){
                i=max(idx[s[j]]+1,i);
            }
            idx[s[j]]=j;
            len=max(len,j-i+1);
            j++;
        }
        //cout<<FS['p']<<" "<<FS['k']<<" "<<FS['w']<<" "<<FS['e']<<" "<<endl;
        return len;
}


int main(){
    string s;
    int len;
    cin>>s;

    len=lengthOfLongestSubstring(s);

    cout<<len<<" ";
}

