#include<bits/stdc++.h>
using namespace std;

string simplifyPath(string path) {

    string simplified_path;
    stack<string> s;
    
    for(int i=0;i<path.size();i++){
        if(path[i]=='/'){
            continue;
        }
        string temp;
        // iterate till we doesn't traverse the whole string and doesn't encounter the last /
        while(i<path.size() && path[i]!='/'){
            // add path to temp string
            temp+=path[i];
            ++i;
        }

        if(temp=="."){
            continue;
        }
        // pop the top element from stack if exists
        else if(temp==".."){
            if(!s.empty()){
                s.pop();
            }
        }
        else{
            s.push(temp);
        }
    }
    // adding all the stack elements to res
    while(!s.empty()){
        simplified_path="/"+s.top()+simplified_path;
        s.pop();
    }
    
    if(simplified_path.size()==0){
        return "/";
    }
    return simplified_path;
}

int main(){
    string s="/home/";
    string s2="/home//foo/";
    string ans=simplifyPath(s2);
    cout<<ans<<endl;
}