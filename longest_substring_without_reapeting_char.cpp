#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int i=0;
    int j=0;
    unordered_map<char,int> charMap;
    int len=0;
    
    while(i<s.length()){
        if(charMap.count(s[i])==0|| charMap[s[i]]<j){
            charMap[s[i]]=i;
            len=max(len,i-j+1);
        }else{
            j=charMap[s[i]]+1;
            charMap[s[i]]=i;
        }
        i++;
    }
    
    return len;
}

int main(){
    string s;
    cin>>s;
    int ans = lengthOfLongestSubstring(s);
    cout<<ans<<endl;
}