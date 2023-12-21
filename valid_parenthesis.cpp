#include<bits/stdc++.h>
using namespace std;

bool valid_parenthesis(string s){
    stack<char> st;
    unordered_map<char,int> mp={{'(',1},{')',1},{'{',2},{'}',2},{'[',3},{']',3}};

    int i=0;
    char top;


    while(i<=s.size()){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        if(s[i]==')' || s[i]=='}' || s[i]==']'){
            if(st.empty()){
                return false;
            }else{
                top=st.top();
                if(mp[top]==mp[s[i]]){
                    st.pop();
                }else{
                    return false;
                }

            }
        }
        i++;
    }
    return st.empty();
}

int main(){
    string s;
    cin>>s;
    bool valid;
    valid=valid_parenthesis(s);
    if(valid){
        cout<<"Valid"<<" ";
    }else{
        cout<<"Not valid"<<" ";
    }
}
