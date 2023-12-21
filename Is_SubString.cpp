#include<bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t) {
    /*
    Bad solution
    int pos=0;
    unordered_map<char,int> char_pos;
    for(int i=0;i<s.length();i++){
        pos++;
        char_pos[s[i]]=pos;
    }

    pos=0;
    for(int i=0;i<t.length();i++){
        if(char_pos.count(t[i])>0){
            pos++;
            if(char_pos[t[i]]!=pos){
                return false;
            }
        }
    }

    //cout<<pos<<" "<<s.length()<<endl;

    return pos==s.length()?true:false;
    */
    //better solution
    int pos=0;
    for(int i=0;i<t.size() && pos<s.size();i++){
        if(s[pos]==t[i]){
            pos++;
        }
    }
    return pos==s.length()?true:false;

}

int main(){
    string s="abc", t="ahbgdc";

    if(isSubsequence(s,t)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}