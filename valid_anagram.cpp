#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    if(s.length()!=t.length()){
        return false;
    }

    vector<int> freq(26,0);

    for(int i=0;s[i]!='\0';i++){
        freq[s[i]-'a']++;
        freq[t[i]-'a']--;
    }

    for(int i=0;i<freq.size();i++){
        if(freq[i]!=0){
            return false;
        }
    }
    return true;
}

int main(){
    string s,t;
    cin>>s>>t;
    string res=(isAnagram(s,t))? "true" : "false";
    cout<<res;
}
